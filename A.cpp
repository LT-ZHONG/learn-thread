//
// Created by zhonglitang on 8/7/23.
//

#include <iostream>

#include "A.h"

int get_value()
{
  int i = 10;
  return i;
}

int main()
{
  int i = get_value();
  const int& k = get_value();
  int&& l = get_value();
  std::cout << &l << std::endl;
  l = 0;
  std::cout << &l << std::endl;

  std::vector<A> v;
  v.emplace_back(25);
  v.emplace_back(75);
  v.insert(v.begin() + 1, A(50));

  A kk {66};
  A jj {88};
  spdlog::info("{}, {}", kk.get_length(), jj.get_length());
  kk.swap(jj);
  spdlog::info("{}, {}", kk.get_length(), jj.get_length());

  v.push_back(std::move(kk));

  return 0;
}