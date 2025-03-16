#include <iostream>
#include <vector>
#include <algorithm>

// Define the size of the arrays
#define MAX_SIZE 200000

// Define the data type for large integers
typedef long long ll;

// Declare the arrays and variables
int a[MAX_SIZE], tmpa[MAX_SIZE], light[MAX_SIZE + 10] = {0};

int main() {
    // Declare variables for input
    int n, k;

    // Read the values of n and k from standard input
    std::cin >> n >> k;

    // Read n integers from standard input and store them in array a
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Initialize the light array based on the initial positions of the lights
    for (int i = 0; i < n; i++) {
        int r, l;
        r = i - a[i];
        l = i + a[i];
        light[(r < 0 ? 0 : r)]++;
        light[(l + 1 > n ? n + 1 : l + 1)]--;
    }

    // Apply the lights k times
    for (int i = 0; i < k; i++) {
        int sum = 0;
        // Update array a based on the light array
        for (int j = 0; j < n; j++) {
            tmpa[j] = a[j];
            sum += light[j];
            a[j] = sum;
        }

        // Adjust the light array based on the new state of array a
        for (int j = 0; j < n; j++) {
            int r = j - tmpa[j];
            int l = j + tmpa[j];
            light[(r < 0 ? 0 : r)]--;
            light[(l + 1 > n ? n + 1 : l + 1)]++;
            r = j - a[j];
            l = j + a[j];
            light[(r < 0 ? 0 : r)]++;
            light[(l + 1 > n ? n + 1 : l + 1)]--;
        }

        // Check if the array a has become stable
        bool isSame = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] != a[j + 1]) {
                isSame = false;
                break;
            }
        }

        // Check if the array a is stable and the first element is n
        if (isSame && a[0] == n) {
            break;
        }
    }

    // Print the final state of array a
    for (int j = 0; j < n; j++) {
        std::cout << a[j];
        if (j != n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
