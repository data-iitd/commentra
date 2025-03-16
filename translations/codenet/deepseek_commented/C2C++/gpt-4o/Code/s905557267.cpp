#include <iostream>
#include <vector>
#include <algorithm>

// Function to return the smaller of two integers
int min(int a, int b) {
    return (a <= b) ? a : b;
}

// Function to remove chains of four or more consecutive identical elements
int Chain(std::vector<int>& b, int n) {
    int count; // To count the length of the chain
    int color; // To store the color of the chain
    std::vector<int> a = b; // Temporary array to hold the modified sequence

    // Iterate through the array to find and remove chains of four or more elements
    for (int i = 0; i < n - 4; i++) {
        if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
            count = 0;
            color = a[i];

            // Remove the chain by setting all elements to 0
            for (int j = i; a[j] == color; j++) {
                a[j] = 0;
                count++;
            }

            // Shift the remaining elements to fill the gap left by the removed chain
            for (int j = 0; i + j + count < 10000; j++) {
                a[i + j] = a[i + j + count];
                a[i + j + count] = 0;
            }

            // Reset the index to start checking from the beginning
            i = -1; // Set to -1 because it will be incremented to 0 in the next iteration
        }
    }

    count = 0;
    while (count < a.size() && a[count] != 0) {
        count++;
    }

    // Check if the remaining sequence is a chain of four or more elements
    if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
        return 0;
    }

    return count;
}

// Main function to read input, process it, and print the result
int main() {
    int n;
    std::vector<int> a(10000);
    int ans;

    while (true) {
        // Initialize the array with zeros
        std::fill(a.begin(), a.end(), 0);

        // Read the number of elements
        std::cin >> n;
        if (n == 0) {
            break;
        }
        ans = n;

        // Read the elements themselves
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        // Iterate over possible starting points for chains of four or more elements
        for (int i = 0; i < n - 4; i++) {
            int count[3] = {0, 0, 0}; // To count occurrences of each color
            for (int j = i; j < i + 4; j++) {
                if (a[j] - 1 >= 0) {
                    count[a[j] - 1]++;
                }
            }

            int color = 0;
            for (int j = 0; j < 3; j++) {
                if (count[j] >= 3) {
                    color = j + 1;
                    break;
                }
            }

            if (color != 0) {
                for (int j = i; j < i + 4; j++) {
                    int buf = a[j];
                    a[j] = color;
                    ans = min(ans, Chain(a, n));
                    a[j] = buf;
                }
            }
        }

        // Print the minimum length after processing
        std::cout << ans << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
