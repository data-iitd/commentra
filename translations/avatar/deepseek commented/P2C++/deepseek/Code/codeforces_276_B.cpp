#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> dt;
    bool x = true;
    int cnt = 0;

    // Iterate over each character in the input string and update the frequency count in the dictionary
    for (char i : s) {
        dt[i]++;
    }

    // Iterate over the items in the dictionary to determine if there is more than one character with an odd frequency
    for (auto& pair : dt) {
        if (pair.second % 2 != 0 && cnt < 1) {
            cnt++;
        } else if (pair.second % 2 != 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    // Determine the output based on the value of cnt and the length of the input string
    if (x) {
        std::cout << "First" << std::endl;
    } else if (!x && s.length() % 2 == 0) {
        std::cout << "Second" << std::endl;
    } else if (!x && s.length() % 2 != 0) {
        std::cout << "First" << std::endl;
    }

    return 0;
}
