//
// Created by zhonglitang on 8/15/23.
//

#ifndef LEARN_THREAD_B_H
#define LEARN_THREAD_B_H

#include <spdlog/spdlog.h>

class B
{
public:
  B() : s("default")
  {
    spdlog::info("Default Constructor, {}", __PRETTY_FUNCTION__ );
  }

  B(const B& other) : s(other.s)
  {
    spdlog::info("Copy Constructor, {}", __PRETTY_FUNCTION__ );
  }

  B(B&& other)  noexcept : s(std::move(other.s))
  {
    spdlog::info("Move Constructor, {}", __PRETTY_FUNCTION__ );
  }

  std::string get_string()
  {
    return s;
  }

private:
  std::string s;
};  // class B

class C : public B
{};

class D : public C
{
public:
  ~D() = default;
};

class E : public B
{
public:
  E() = default;

  ~E() = default;

  E(E&& other) = default;
};

B temp(B b)
{
  spdlog::info(__PRETTY_FUNCTION__ );
  return b;
}

#endif //LEARN_THREAD_B_H
