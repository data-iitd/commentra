#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int magic = 1000000007;

int N;
std::vector<int> p;

// Function to check if a given number n is present in the p vector
int find(int n) {
    return std::find(p.begin(), p.end(), n) != p.end() ? 0 : 1;
}

// Main logic of the problem
void solve() {
    int X;
    std::cin >> X;
    std::cout << X << std::endl;
    std::cin >> N;
    p.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    // Check if X or its neighbors are present in the p vector
    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            std::cout << X - i << std::endl;
            exit(0);
        }
        if (find(X + i) == 1) {
            std::cout << X + i << std::endl;
            exit(0);
        }
    }

    // Output generation part is not present in the code
    // ans = 0;
    // std::cout << ans << std::endl;

    // If ans > 0, print "Yes" and exit; otherwise, print "No"
    // if (ans > 0) {
    //     std::cout << "Yes" << std::endl;
    // } else {
    //     std::cout << "No" << std::endl;
    // }
}

int main() {
    solve(); // Call the solve function
    return 0;
}
