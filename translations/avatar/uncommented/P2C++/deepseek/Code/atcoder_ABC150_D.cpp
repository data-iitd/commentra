#include <iostream>
#include <vector>
#include <set>
#include <numeric> // for std::gcd

int main() {
    int n, num;
    std::cin >> n >> num;
    std::set<int> num_set;
    {
        int x;
        for (int i = 0; i < n; ++i) {
            std::cin >> x;
            num_set.insert(x);
        }
    }
    std::set<int> two_times_set;
    for (int i : num_set) {
        for (int j = 1; j <= 29; ++j) {
            i /= 2;
            if (i % 2 != 0) {
                two_times_set.insert(j);
                break;
            }
        }
        if (two_times_set.size() != 1) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    std::vector<int> num_list(num_set.begin(), num_set.end());
    int lcm = num_list[0];
    for (int i = 1; i < num_list.size(); ++i) {
        lcm = lcm * num_list[i] / std::gcd(lcm, num_list[i]);
    }
    std::cout << (num - lcm / 2) / lcm + 1 << std::endl;
    return 0;
}

