#include <thread>
#include <chrono>
#include <vector>
#include <spdlog/spdlog.h>

void sleep()
{
  using namespace std::chrono_literals;
  std::this_thread::sleep_for(3s);
}

void thread_function(std::string s)
{
  sleep();
  spdlog::info("{} {}", __PRETTY_FUNCTION__ , s);
  s = "jjj";
  spdlog::info("{} {}", __PRETTY_FUNCTION__ , s);
}

void thread_function2(int i)
{
  spdlog::info("{} {}", __PRETTY_FUNCTION__ , i);
}

void foo(std::string& s)
{
  spdlog::info("{} {}", __PRETTY_FUNCTION__ , s);
}

void foo(std::string&& s)
{
  spdlog::info("{} {}", __PRETTY_FUNCTION__ , s);
  s = "ll";
  spdlog::info("{} {}", __PRETTY_FUNCTION__ , s);
}

struct MyFunctor
{
  void operator()()
  {
    sleep();
    spdlog::info(__PRETTY_FUNCTION__ );
  }
};

int main()
{
  MyFunctor my_functor;

  std::string s = "xxx";

  std::thread t (&thread_function, std::move(s));
  std::thread t2 (my_functor);

  t.join();
  t2.join();

  std::vector<std::thread> workers;
  for (int i = 0; i < 5; ++i)
  {
    workers.emplace_back([i]()
    {
      spdlog::info("{} {}", __PRETTY_FUNCTION__ , i);
    });
    workers.emplace_back(&thread_function2, i);
  }

  std::for_each(workers.begin(), workers.end(), [](std::thread& t)
  {
    t.join();
  });

  std::string ss = "K Coffee";
  foo(ss);
  foo("Mc Coffee");
  foo(std::move(ss));

//  t.detach();
//  if (t.joinable())
//    t.join();

  return 0;
}
