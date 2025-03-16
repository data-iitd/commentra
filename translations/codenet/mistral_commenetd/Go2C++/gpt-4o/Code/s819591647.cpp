// problem_b.cpp
// This is the main file for problem B solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

const int constMod = 1e9 + 7; // Constants definition

// Function to read an integer from standard input
int getInt() {
    int i;
    std::cin >> i;
    return i;
}

// Function to read n integers and return a vector
std::vector<int> getIntVector(int n) {
    std::vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

// Main function to solve the problem
void solve() {
    int n = getInt();
    int m = getInt();
    std::vector<int> a = getIntVector(n);

    int sum = std::accumulate(a.begin(), a.end(), 0);

    int count = 0;
    for (int v : a) {
        double rate = static_cast<double>(sum) / (4 * m);
        if (static_cast<double>(v) >= rate) {
            count++;
        }
    }

    if (count >= m) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

// Main function
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
