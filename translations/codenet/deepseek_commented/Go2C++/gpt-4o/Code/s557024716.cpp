#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to generate all patterns of length k
void generatePatterns(vector<int>& pattern, vector<int>& elems, int k, vector<vector<int>>& result) {
    if (pattern.size() == k) {
        result.push_back(pattern);
        return;
    }

    for (int e : elems) {
        pattern.push_back(e);
        generatePatterns(pattern, elems, k, result);
        pattern.pop_back(); // backtrack
    }
}

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k; // Read three integers a, b, c and integer k

    // Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3
    vector<int> elems = {0, 1, 2, 3};
    vector<vector<int>> patterns;
    vector<int> currentPattern;
    generatePatterns(currentPattern, elems, k, patterns);

    // Iterate through each pattern to check the condition
    for (const auto& P : patterns) {
        int r = a, g = b, c_temp = c; // Initialize r, g, and c_temp with a, b, and c respectively
        for (int i : P) {
            if (i == 0) {
                continue; // If the operation is 0, do nothing
            } else if (i == 1) {
                r *= 2; // Double the value of r
            } else if (i == 2) {
                g *= 2; // Double the value of g
            } else if (i == 3) {
                c_temp *= 2; // Double the value of c
            }
        }

        // Check if the condition b > a and c > b is met
        if (g > r && c_temp > g) {
            cout << "Yes" << endl; // Print "Yes" if the condition is met
            return 0;
        }
    }
    cout << "No" << endl; // Print "No" if no pattern meets the condition
    return 0;
}

/<END-OF-CODE>
