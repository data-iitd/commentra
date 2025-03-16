
#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::string m;
    std::cin >> m;

    std::map<char, int> charCount;
    for (char c : m) {
        charCount[c]++;
    }

    bool possible = true;
    for (auto const& [c, count] : charCount) {
        if (count >= (n / 2) + 1) {
            possible = false;
            break;
        }
    }

    std::cout << (possible? "YES" : "NO") << std::endl;

    return 0;
}
