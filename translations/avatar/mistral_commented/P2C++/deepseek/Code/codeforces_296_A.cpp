#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> m;
    std::string input;
    std::cin >> input;
    std::string delimiter = " ";
    size_t pos = 0;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        m.push_back(input.substr(0, pos));
        input.erase(0, pos + delimiter.length());
    }
    m.push_back(input);

    bool possible = true;
    std::unordered_set<std::string> unique_chars(m.begin(), m.end());

    for (const auto& i : unique_chars) {
        int count = 0;
        for (const auto& char_in_m : m) {
            if (char_in_m == i) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
            possible = false;
            break;
        }
    }

    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}
