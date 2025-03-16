
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::string run(std::string s, std::string t) {
    // Count the frequency of each character in string s and sort the frequencies
    std::map<char, int> charCountS;
    for (char c : s) {
        charCountS[c]++;
    }
    std::vector<int> freqS(charCountS.begin(), charCountS.end());
    std::sort(freqS.begin(), freqS.end());
    
    // Count the frequency of each character in string t and sort the frequencies
    std::map<char, int> charCountT;
    for (char c : t) {
        charCountT[c]++;
    }
    std::vector<int> freqT(charCountT.begin(), charCountT.end());
    std::sort(freqT.begin(), freqT.end());
    
    // Compare the sorted frequency lists of both strings
    if (freqS == freqT) {
        return "Yes";  // Return 'Yes' if the frequency distributions are the same
    } else {
        return "No";   // Return 'No' if the frequency distributions are different
    }
}

int main() {
    // Read input strings s and t from the user
    std::string s, t;
    std::cin >> s >> t;
    
    // Print the result of the run function which checks the character frequency
    std::cout << run(s, t) << std::endl;
    
    return 0;
}

