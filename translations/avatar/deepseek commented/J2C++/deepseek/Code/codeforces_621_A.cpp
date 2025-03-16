#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> list(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> list[i];
    }

    long long sum = 0;
    std::vector<long long> odd;

    for (long long i : list) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            odd.push_back(i);
        }
    }

    std::sort(odd.begin(), odd.end());

    for (long long i : odd) {
        sum += i;
    }

    if (odd.size() % 2 != 0) {
        sum -= odd[0];
    }

    std::cout << sum << std::endl;

    return 0;
}

