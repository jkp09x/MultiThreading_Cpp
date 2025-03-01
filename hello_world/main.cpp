#include <iostream>
#include <thread>

void printMsg(int thread_num)
{
  std::cout << "Hello from thread " << thread_num << "!" << std::endl;
}

int main()
{
  std::thread t1(printMsg, 1);
  std::thread t2(printMsg, 2);

  t1.join();
  t2.join();
  
  std::cout << "Hello from Main" << std::endl;

  return 0;
}
