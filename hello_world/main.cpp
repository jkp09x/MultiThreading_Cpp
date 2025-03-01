#include <iostream>
#include <thread>
#include <mutex>

// Global mutex variable
std::mutex mtx;

void printMsg(int thread_num)
{
  std::lock_guard<std::mutex> lock(mtx);
  std::cout << "Hello from thread " << thread_num << "!" << std::endl;
}

int main()
{
  std::thread t1(printMsg, 1);
  std::thread t2(printMsg, 2);

  t1.join();
  t2.join();
  
  // Lock the mutex to ensure this is printed without other threads interfering.
  std::lock_guard<std::mutex> lock(mtx);
  std::cout << "Hello from Main." << std::endl;

  return 0;
}
