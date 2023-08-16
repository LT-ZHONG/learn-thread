//
// Created by zhonglitang on 8/15/23.
//

#include "B.h"

int main()
{
//  B b1 = temp(B());
//  spdlog::info("Before Move : b1 = {}", b1.get_string());
//  B b2 = std::move(b1);
//  spdlog::info("After Move : b1 = {}", b1.get_string());
//  spdlog::info("After Move : b2 = {}", b2.get_string());

//  C c1;
//  C c2 = std::move(c1);

  D d1;
  D d2 = std::move(d1);

  E e1;
  E e2 = std::move(e1);

  return 0;
}