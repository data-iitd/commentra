
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Initialize logger to include short file names
void initLogger() {
    // Your implementation here
}

// Function to read the next word
string next() {
    // Your implementation here
}

// Function to read the next line
string nextLine() {
    // Your implementation here
}

// Function to read the next integer
int nextInt() {
    // Your implementation here
}

int main() {
    initLogger();

    // Create a new scanner to read input
    // Your implementation here

    // Read two integers from the input
    int x = nextInt();
    int y = nextInt();

    // Define an array containing three slices, each representing a group of months with the same number of days
    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

    // Iterate over the array to determine which group each of the integers belongs to
    int xt = -1, yt = -1;
    for (int i = 0; i < a.size(); i++) {
        for (int n : a[i]) {
            // log.Println(n) // Uncomment to log each number in the array
            if (x == n) {
                xt = i;
            }
            if (y == n) {
                yt = i;
            }
        }
    }

    // Compare the groups of x and y to determine if they belong to the same group
    if (xt == yt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

