#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate all patterns of length k from the given elements
void generatePatterns(vector<int>& elems, int k, vector<vector<int>>& results, vector<int>& current) {
    if (current.size() == k) {
        results.push_back(current); // Add the completed pattern to results
        return;
    }

    for (int e : elems) {
        current.push_back(e); // Append the new element
        generatePatterns(elems, k, results, current); // Recursively generate patterns
        current.pop_back(); // Backtrack
    }
}

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k; // Read three integers and the number of patterns

    vector<int> elems = {0, 1, 2, 3}; // Elements to generate patterns
    vector<vector<int>> patterns; // To hold all generated patterns
    vector<int> current; // Current pattern being built

    // Generate all possible patterns of length k
    generatePatterns(elems, k, patterns, current);

    // Iterate through each generated pattern
    for (const auto& P : patterns) {
        int r = a, g = b, b_val = c; // Initialize color values for each pattern
        // Apply the pattern to modify the color values
        for (int i = 0; i < P.size(); i++) {
            if (P[i] == 0) {
                continue; // Skip if the pattern element is 0
            } else if (P[i] == 1) {
                r *= 2; // Double the red value
            } else if (P[i] == 2) {
                g *= 2; // Double the green value
            } else if (P[i] == 3) {
                b_val *= 2; // Double the blue value
            }
        }

        // Check if the modified values satisfy the condition
        if (g > r && b_val > g) {
            cout << "Yes" << endl; // Print "Yes" if the condition is met
            return 0;
        }
    }
    cout << "No" << endl; // Print "No" if no pattern satisfies the condition
    return 0;
}

/* <END-OF-CODE> */
