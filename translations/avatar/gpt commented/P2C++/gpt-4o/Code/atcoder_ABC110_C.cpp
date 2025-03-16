#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::string run(const std::string& s, const std::string& t) {
    // Count the frequency of each character in string s
    std::unordered_map<char, int> freq_s;
    for (char c : s) {
        freq_s[c]++;
    }

    // Count the frequency of each character in string t
    std::unordered_map<char, int> freq_t;
    for (char c : t) {
        freq_t[c]++;
    }

    // Create vectors to store the frequencies
    std::vector<int> ss, tt;

    for (const auto& pair : freq_s) {
        ss.push_back(pair.second);
    }
    for (const auto& pair : freq_t) {
        tt.push_back(pair.second);
    }

    // Sort the frequency vectors
    std::sort(ss.begin(), ss.end());
    std::sort(tt.begin(), tt.end());

    // Compare the sorted frequency vectors of both strings
    if (ss == tt) {
        return "Yes";  // Return "Yes" if the frequency distributions are the same
    } else {
        return "No";   // Return "No" if the frequency distributions are different
    }
}

int main() {
    // Read input strings s and t from the user
    std::string s, t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    
    // Print the result of the run function which checks the character frequency
    std::cout << run(s, t) << std::endl;

    return 0;
}

// <END-OF-CODE>
