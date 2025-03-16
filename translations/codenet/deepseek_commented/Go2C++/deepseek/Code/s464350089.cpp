#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

const long long mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read the initial height `h` and the number of attacks `n`
    long long h, n;
    std::cin >> h >> n;

    // Initialize a variable to keep track of the total damage dealt
    long long a = 0;

    // Read each attack's damage and accumulate the total damage
    for (long long i = 0; i < n; ++i) {
        long long damage;
        std::cin >> damage;
        a += damage;
    }

    // Check if the total damage is greater than or equal to the initial height
    if (h > a) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}
