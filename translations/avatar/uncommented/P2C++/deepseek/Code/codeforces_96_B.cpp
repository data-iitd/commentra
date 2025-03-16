#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> l;
long long limit = 10000000000;

void gen(long long number, int four, int seven) {
    if (number > limit) {
        return;
    }
    if (number > 0 && four == seven) {
        l.push_back(number);
    }
    gen(number * 10 + 4, four + 1, seven);
    gen(number * 10 + 7, four, seven + 1);
}

int main() {
    gen(0, 0, 0);
    std::sort(l.begin(), l.end());
    long long n;
    std::cin >> n;
    long long ans = 0;
    for (long long val : l) {
        if (val >= n) {
            ans = val;
            break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
