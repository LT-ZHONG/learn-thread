//
// Created by zhonglitang on 8/16/23.
//

#ifndef LEARN_THREAD_RACE_CONDITION_H
#define LEARN_THREAD_RACE_CONDITION_H

#include <mutex>
#include <vector>
#include <iostream>

std::mutex mutex;

class stack
{
public:
  stack() = default;
  ~stack() = default;

  int pop()
  {
    std::lock_guard<std::mutex> guard(mutex);
    int val = data_.back();
    data_.erase(data_.end() - 1);
    return val;
  }

  void push(int n)
  {
    std::lock_guard<std::mutex> guard(mutex);
    data_.push_back(n);
  }

  void print()
  {
    std::cout << "Initial stack : ";
    for (int item : data_)
      std::cout << item << ", ";
    std::cout << std::endl;
  }

  size_t get_size()
  {
    return data_.size();
  }

private:
  std::vector<int> data_;
};


#endif //LEARN_THREAD_RACE_CONDITION_H
