#include <iostream>
#include <string>
#include <set>

int aaa(int n) {
    if (n > N) {
        return 0;
    }
    int ans = (std::set<char>(std::to_string(n)).size() == 3 && std::set<char>({'7', '5', '3'}).size() == 3) ? 1 : 0;
    for (char i : {'7', '5', '3'}) {
        ans += aaa(n * 10 + i - '0');
    }
    return ans;
}

int main() {
    int N;
    std::cin >> N;
    std::cout << aaa(0) << std::endl;
    return 0;
}

