#include <iostream>
#include <string>
#include <set>

int aaa(int n, int N) {
    if (n > N) {
        return 0;
    }

    int ans = (std::set<char>(std::to_string(n)) == std::set<char>{'7', '5', '3'}) ? 1 : 0;

    for (char i : "753") {
        ans += aaa(n + (i - '0'), N);
    }

    return ans;
}

int main() {
    int N;
    std::cin >> N;
    std::cout << aaa(0, N) << std::endl;
    return 0;
}

