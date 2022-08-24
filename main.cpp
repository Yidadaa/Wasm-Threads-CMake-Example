#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

void runner(int x) { std::cout << "thread is running " << x << std::endl; }

int main() {
  std::cout << "hello world" << std::endl;

  std::vector<std::thread> ths;
  for (int i = 0; i < 4; ++i) {
    ths.push_back(std::thread(runner, i));
  }

  for (auto &t : ths) {
    t.detach();
  }

  std::cerr << "running end" << std::endl;
}
