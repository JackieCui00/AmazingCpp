#include <iostream>
#include <string>
#include <type_traits>

// a example for user-defined literals
// see https://en.cppreference.com/w/cpp/language/user_literal

unsigned long long operator ""_fallback(const char* orig) {
    std::cout << "user defined literal for interger fallback is called, with orig:"
        << orig << std::endl;
    return 0ULL;
}

unsigned long long operator ""_i(unsigned long long orig) {
    std::cout << "user defined literal for interger is called, with orig:"
        << orig << std::endl;
    return orig * 1000ULL;
}

double long operator "" _d(long double orig) {
    std::cout << "user defined literal for double is called, with orig:"
        << orig << std::endl;
    return orig * 1000;
}

std::string operator "" _s(const char* orig, std::size_t orig_size) {
    std::cout << "user defined literal for string is called, with orig:"
        << orig << ", orig_size:" << orig_size << std::endl;
    return "user-defined-string:" + std::string(orig, orig_size);
}

int main(int argc, char* argv[]) {
    auto f = 1000_fallback;
    static_assert(std::is_same_v<decltype(f), unsigned long long>, "impossible");
    std::cout << "f:" << f << std::endl << std::endl;

    auto a = 1000_i;
    static_assert(std::is_same_v<decltype(a), unsigned long long>, "impossible");
    std::cout << "a:" << a << std::endl << std::endl;

    auto d = 1000._d;
    static_assert(std::is_same_v<decltype(d), long double>, "impossible");
    std::cout << "d:" << d <<  std::endl << std::endl;

    auto s = "1000"_s;
    static_assert(std::is_same_v<decltype(s), std::string>, "impossible");
    std::cout << "s:" << s << std::endl << std::endl;

    return 0;
}
