#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Set log flags to show the file name and line number for log messages
    // (C++ does not have a built-in equivalent to Go's log package)

    // Initialize a new scanner to read input
    // (C++ does not have a built-in equivalent to Go's bufio package)
    // Instead, we'll use cin for input

    // Read two integers from input
    int x, y;
    cin >> x >> y;

    // Initialize variables to store the category indices of x and y
    int xt = 0, yt = 0;

    // Define a 2D vector where each sub-vector represents a category of numbers
    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

    // Iterate through the categories to find the indices of x and y
    for (int i = 0; i < a.size(); ++i) {
        for (int n : a[i]) {
            // Check if the current number matches x
            if (x == n) {
                xt = i; // Store the category index for x
            }
            // Check if the current number matches y
            if (y == n) {
                yt = i; // Store the category index for y
            }
        }
    }

    // Compare the category indices of x and y and print the result
    if (xt == yt) {
        cout << "Yes" << endl; // x and y belong to the same category
    } else {
        cout << "No" << endl;  // x and y belong to different categories
    }

    return 0;
}
