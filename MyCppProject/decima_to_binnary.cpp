#include <iostream>
#include <bitset>

int main() {
    unsigned long long n = 16ULL;
    // Note: 10^10 requires at least 34 bits
    std::cout << std::bitset<8>(n) << std::endl;
    return 0;
}