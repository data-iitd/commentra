
#include <iostream>
#include <vector>

int main() {
    const int MX = 10000;
    std::vector<int> sieve(MX);
    std::vector<int> primes;

    for (int i = 2; i < MX; i++) {
        if (sieve[i]!= 0) {
            continue;
        }
        primes.push_back(i);
        for (int j = i + i; j < MX; j += i) {
            sieve[j] = i;
        }
    }

    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        ans++;
        for (int j = 0; j < primes.size(); j++) {
            if (x > primes[j] && x % primes[j] == 0) {
                ans--;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

