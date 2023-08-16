//
// Created by zhonglitang on 8/16/23.
//

#include <list>
#include <mutex>
#include <thread>
#include <string>
#include <iostream>

#include "tsm.h"

std::mutex mutex;

std::list<int> ll;

void shared_cout(const std::string& msg, int id)
{
  mutex.lock();
  std::cout << msg << id << std::endl;
  mutex.unlock();
}

void thread_function()
{
  for (int i = 0; i < 100; ++i)
    shared_cout("thread function : ", i);
}

void add_to_list(int max, int interval)
{
  // the access to this function is mutually exclusive
  std::lock_guard<std::mutex> guard(mutex);
  for (int i = 0; i < max; ++i)
  {
    if (i % interval == 0)
      ll.push_back(i);
  }
}

void print_list()
{
  // the access to this function is mutually exclusive
  std::lock_guard<std::mutex> guard(mutex);
  for (int & item : ll)
    std::cout << item << ", ";
}

int main()
{
  std::thread t (&thread_function);
  for (int i = 0; i < 100; ++i)
    shared_cout("main thread : ", i);
  t.join();

  int max = 100;
  std::thread t1 (add_to_list, max, 1);
  std::thread t2 (add_to_list, max, 10);
  std::thread t3 (print_list);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}