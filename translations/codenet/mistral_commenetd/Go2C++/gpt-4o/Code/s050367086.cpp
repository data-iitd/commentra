// Include necessary headers
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <cstdlib>

// Function to read the next string from input
std::string getNextString(std::istringstream &input) {
    std::string s;
    input >> s;
    return s;
}

// Function to read and convert the next integer from input
int getNextInt(std::istringstream &input) {
    int i;
    input >> i;
    return i;
}

// Function to read and convert the next long long from input
long long getNextInt64(std::istringstream &input) {
    long long i;
    input >> i;
    return i;
}

// Function to read and convert the next double from input
double getNextFloat64(std::istringstream &input) {
    double i;
    input >> i;
    return i;
}

// Function to find the root of the given index in the union-find structure
int root(int i, std::vector<int> &uni) {
    if (i == uni[i]) {
        return i;
    }
    uni[i] = root(uni[i], uni);
    return uni[i];
}

// Class representing a suffix array data structure
class MP {
public:
    std::string s; // Input string
    std::vector<int> table; // Suffix array

    // Initialize the MP structure with the given string s
    void init(const std::string &s) {
        this->s = s;
        int n = s.length();
        table.resize(n + 1);
        table[0] = -1; // Set first index to -1 for initialization
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && s[i] != s[j]) {
                j = table[j];
            }
            j++;
            table[i + 1] = j; // Set table[i] to the index of the next occurrence
        }
    }
};

// Main function
int main() {
    // Read input from standard input
    std::string inputStr;
    std::getline(std::cin, inputStr);
    std::istringstream input(inputStr);

    // Read the first two strings from the input
    std::string s = getNextString(input);
    std::string t = getNextString(input);

    // Initialize variables and structures
    int ns = s.length();
    int nt = t.length();
    std::vector<std::string> ss((nt - 1) / ns + 1, s);

    // Combine all ss strings into one long string
    std::string sss = std::string(ss.begin(), ss.end()) + std::string(ss.begin(), ss.end());

    // Initialize boolean array ok to keep track of unique characters
    std::vector<bool> ok(ns, false);

    // Initialize MP and other variables
    MP mp;
    mp.init(t);
    int m = 0;

    // Initialize uni array with indices from 0 to n-1
    std::vector<int> uni(ns);
    for (int i = 0; i < ns; i++) {
        uni[i] = i;
    }

    // Iterate through all characters in string s
    for (int i = 0; i < ns; i++) {
        bool o = true;
        m = 0;

        // Check if current character in s matches the character at the same position in t
        while (m < nt) {
            if (t[m] != sss[i + m]) {
                o = false;
                break;
            }
            m++;
        }

        // If all characters match, update ok and m accordingly
        if (o) {
            ok[i] = true;
            i += nt - mp.table[m];
            m = mp.table[m];
        }

        // While characters in s and t do not match, update i and m accordingly
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp.table[m];
            m = mp.table[m];
        }

        // Decrement i and increment m to move to the next pair of characters
        i--;
        m++;
    }

    // Initialize variable ans to store the answer
    int ans = 0;

    // Iterate through all characters in string s again
    for (int i = 0; i < ns; i++) {
        if (!ok[i]) continue;
        if (!ok[(i + nt) % ns]) continue;

        // Calculate roots r and rr of indices i and (i + nt) % ns respectively
        int r = root(i, uni);
        int rr = root((i + nt) % ns, uni);

        // If roots r and rr are equal, print -1 and exit the program
        if (rr == r) {
            std::cout << -1 << std::endl;
            return 0;
        }

        // Update uni array with root r
        uni[rr] = r;
    }

    // Initialize counter array to store the frequency of each root
    std::vector<int> counter(ns, 0);

    // Iterate through all roots and update their frequencies in counter array
    for (int i = 0; i < ns; i++) {
        int r = root(i, uni);
        if (!ok[r]) continue;
        counter[r]++;
    }

    // Find the maximum frequency in counter array and store it in variable ans
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    // Print the answer
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
