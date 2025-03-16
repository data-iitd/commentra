#include <iostream>
#include <vector>

int main() {
    // Read the number of characters
    int n;
    std::cin >> n;

    // Read the sequence of characters
    std::string s;
    std::cin >> s;

    // Create a vector to hold the numeric representation of colors
    std::vector<int> ns(n);
    // Convert characters to their respective numeric values
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'R':
                ns[i] = 0; // 'R' is represented as 0
                break;
            case 'G':
                ns[i] = 1; // 'G' is represented as 1
                break;
            case 'B':
                ns[i] = 2; // 'B' is represented as 2
                break;
        }
    }

    // Create a 2D vector to hold cumulative counts of each color up to each index
    std::vector<std::vector<int>> rgb(n + 1, std::vector<int>(3, 0));

    // Populate the cumulative counts for each color
    for (int i = 1; i <= n; i++) {
        rgb[i] = rgb[i - 1]; // Carry forward the previous counts
        rgb[i][ns[i - 1]]++; // Increment the count for the current color
    }

    // Variable to hold the total count of valid triplets
    int sum = 0;

    // Iterate through all pairs of indices to find valid triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            // Check if the colors at indices i and j are different
            if (ns[i] != ns[j]) {
                // Determine the third color that completes the triplet
                int tn = 3 - ns[i] - ns[j];
                // Count how many times the third color appears after index j
                sum += rgb[n][tn] - rgb[j + 1][tn];
                // Check if the third color appears at the position k
                int k = 2 * j - i;
                if (k < n && ns[k] == tn) {
                    sum--; // Adjust the count if the third color is at position k
                }
            }
        }
    }

    // Output the total count of valid triplets
    std::cout << sum << std::endl;

    return 0;
}

// <END-OF-CODE>
