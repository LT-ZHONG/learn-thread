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
    spdlog::info("{} length = {} Constructor", __PRETTY_FUNCTION__ , length_);
  }

  ~A()
  {
    spdlog::warn("{} length = {} Destructor", __PRETTY_FUNCTION__ , length_);
    if (data_ != nullptr)
    {
      spdlog::warn("Deleting Resource.");
      delete[] data_;
    }
  }

  /**
   * This is a copy constructor for class A.
   * It takes in a reference to another object of class A and creates a new object with the same length and data.
   * The length is copied from the other object and the data is deep copied using std::copy.
   * @param other
   */
  A(const A& other) : length_(other.length_), data_(new int[other.length_])
  {
    spdlog::info("{} length = {} Copy Constructor", __PRETTY_FUNCTION__ , other.length_);
    std::copy(other.data_, other.data_ + length_, data_);
  }

  /**
   * This is a move constructor for class A.
   * It takes an rvalue reference to another object of type A (other) and
   * transfers the ownership of its resources (length_ and data_) to the newly created object.
   * @param other
   */
  A(A&& other) noexcept : length_(0), data_(nullptr)
  {
    spdlog::info("{} length = {} Move Constructor", __PRETTY_FUNCTION__ , other.length_);
    length_ = other.length_;
    data_ = other.data_;

    other.length_ = 0;
    other.data_ = nullptr;
  }

  /**
   * This is the copy assignment operator of class A.
   * It takes a constant reference to another object of class A as a parameter.
   * @param other
   * @return
   */
  A& operator=(const A& other)
  {
    spdlog::info("{} length = {} Copy Assignment", __PRETTY_FUNCTION__ , other.length_);
    if (this != &other)
    {
      delete[] data_;
      length_ = other.length_;
      data_ = new int[length_];
      std::copy(other.data_, other.data_ + length_, data_);
    }
    return *this;
  }

  /**
   * This is a move assignment operator for class A.
   * It takes an rvalue reference to another object of class A (other) and
   * assigns its data members to the current object.
   * The function is marked as noexcept, indicating that it does not throw any exceptions.
   * @param other
   * @return
   */
  A& operator=(A&& other) noexcept
  {
    spdlog::info("{} length = {} Move Assignment", __PRETTY_FUNCTION__ , other.length_);
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

private:
  size_t length_;
  int* data_;
};


#endif //LEARN_THREAD_A_H
