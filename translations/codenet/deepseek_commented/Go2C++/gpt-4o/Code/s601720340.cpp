// Includes necessary libraries
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

// Constants
const int magic = 1000000007;

// Function to find if a number exists in the array
int find(int n, const std::vector<int>& p) {
    return std::find(p.begin(), p.end(), n) != p.end() ? 0 : 1;
}

// Main logic function
void solve() {
    int X, N;
    std::cin >> X >> N;
    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    // Search for the closest number to X in the array p
    for (int i = 0; i <= 100; i++) {
        if (find(X - i, p) == 1) {
            std::cout << X - i << std::endl;
            return;
        }
        if (find(X + i, p) == 1) {
            std::cout << X + i << std::endl;
            return;
        }
    }
}

// Entry point of the program
int main() {
    // Uncomment the following lines for profiling if needed
    /*
    std::string cpuprofile, memprofile;
    std::cin >> cpuprofile >> memprofile;
    if (!cpuprofile.empty()) {
        std::ofstream cpu_file(cpuprofile);
        // Start CPU profiling
    }
    */

    solve();

    /*
    if (!memprofile.empty()) {
        std::ofstream mem_file(memprofile);
        // Write memory profile
    }
    */

    return 0;
}

// Helper functions can be added here if needed

// <END-OF-CODE>
