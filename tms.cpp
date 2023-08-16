//
// Created by zhonglitang on 8/16/23.
//

#include <vector>
#include <thread>

#include <spdlog/spdlog.h>

#include "tms.h"

void task(int& i)
{
  spdlog::info("thread function: {}", i);
}

int main()
{
  std::vector<std::thread> workers;
  for (int i = 0; i < 5; ++i)
  {
    auto t = std::thread(&task, std::ref(i));
    workers.push_back(std::move(t));
  }
  spdlog::info("main thread");

  std::for_each(workers.begin(), workers.end(), [](std::thread& t){
    assert(t.joinable());
    t.join();
  });

  return 0;
}