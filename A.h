//
// Created by zhonglitang on 8/7/23.
//

#ifndef LEARN_THREAD_A_H
#define LEARN_THREAD_A_H

#include <spdlog/spdlog.h>

class A
{
public:
  explicit A(size_t length) : length_(length), data_(new int[length])
  {
    spdlog::info("{} length = {} Constructor : {}", __PRETTY_FUNCTION__ , length_, __LINE__);
  }

  ~A()
  {
    spdlog::warn("{} length = {} Destructor : {}", __PRETTY_FUNCTION__ , length_, __LINE__);
    if (data_ != nullptr)
    {
      spdlog::warn("Deleting Resource.");
      delete[] data_;
    }
  }

  A(const A& other) : length_(other.length_), data_(new int[other.length_])
  {
    spdlog::info("{} length = {} Copy Constructor : {}", __PRETTY_FUNCTION__ , other.length_, __LINE__);
    std::copy(other.data_, other.data_ + length_, data_);
  }

  A(A&& other) noexcept : length_(0), data_(nullptr)
  {
    spdlog::info("{} length = {} Move Constructor : {}", __PRETTY_FUNCTION__ , other.length_, __LINE__);
    length_ = other.length_;
    data_ = other.data_;

    other.length_ = 0;
    other.data_ = nullptr;
  }

  A& operator=(const A& other)
  {
    spdlog::info("{} length = {} Copy Assignment : {}", __PRETTY_FUNCTION__ , other.length_, __LINE__);
    if (this != &other)
    {
      delete[] data_;
      length_ = other.length_;
      data_ = new int[length_];
      std::copy(other.data_, other.data_ + length_, data_);
    }
    return *this;
  }

  A& operator=(A&& other) noexcept
  {
    spdlog::info("{} length = {} Move Assignment : {}", __PRETTY_FUNCTION__ , other.length_, __LINE__);
    if (this != &other)
    {
      delete[] data_;
      length_ = other.length_;
      data_ = other.data_;
      other.length_ = 0;
      other.data_ = nullptr;
    }
    return *this;
  }

  void swap(A& other)
  {
    A temp = std::move(other);
    other = std::move(*this);
    *this = std::move(temp);
  }

  [[nodiscard]]
  size_t get_length() const
  {
    return length_;
  }

private:
  size_t length_;
  int* data_;
};


#endif //LEARN_THREAD_A_H
