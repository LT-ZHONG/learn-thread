//
// Created by zhonglitang on 8/16/23.
//

#include <thread>

#include "race_condition.h"


void process(int val, const std::string& s)
{
  std::lock_guard<std::mutex> guard(mutex);
  std::cout << s << " : " << val << std::endl;
}

void thread_function(stack& st, const std::string& s)
{
  int val = st.pop();
  process(val, s);
}

int main()
{
  stack st;
  for (int i = 0; i < 10; ++i)
    st.push(i);
  st.print();

  while (true)
  {
    if (st.get_size() > 0)
    {
      std::thread t1 (&thread_function, std::ref(st), "thread1");
      t1.join();
    }
    else
      break;

    if (st.get_size() > 0)
    {
      std::thread t2 (&thread_function, std::ref(st), "thread2");
      t2.join();
    }
    else
      break;
  }
  return 0;
}