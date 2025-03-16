#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> dt;

    // Count the occurrences of each character in the input string
    for (char i : s) {
        dt[i]++;
    }

    int cnt = 0;
    bool x = true;

    // Check the counts of each character to determine the number of odd occurrences
    for (auto& pair : dt) {
        if (pair.second % 2 != 0 && cnt < 1) {
            cnt++;  // Count the first odd occurrence
        } else if (pair.second % 2 != 0 && cnt >= 1) {
            x = false;  // More than one odd occurrence found, set flag to false
            break;
        }
    }

    // Determine the output based on the number of odd occurrences and the length of the input
    if (x) {
        std::cout << "First" << std::endl;  // If there are no more than one odd occurrences, print "First"
    } else if (!x && s.length() % 2 == 0) {
        std::cout << "Second" << std::endl;  // If there are more than one odd occurrences and the length is even, print "Second"
    } else if (!x && s.length() % 2 != 0) {
        std::cout << "First" << std::endl;  // If there are more than one odd occurrences and the length is odd, print "First"
    }

    return 0;
}
