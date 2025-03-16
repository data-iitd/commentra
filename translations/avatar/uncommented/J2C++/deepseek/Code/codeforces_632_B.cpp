#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::string s;
    std::cin >> s;
    long long sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch == 'B') sum += a[i];
    }
    long long ans = sum;
    long long sum1 = sum;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        ans = std::max(ans, sum1);
    }
    sum1 = sum;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        ans = std::max(ans, sum1);
    }
    std::cout << ans << std::endl;
    return 0;
}

