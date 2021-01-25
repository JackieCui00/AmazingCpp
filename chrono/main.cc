#include <iostream>
#include <chrono>
#include <ostream>
#include <thread>

int main(int argc, char* argv[]) {
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto end = std::chrono::system_clock::now();

    std::chrono::sys_time<decltype(start)::duration> t = start;

    std::cout << "start:" << t << std::endl;
    return 0;
}
