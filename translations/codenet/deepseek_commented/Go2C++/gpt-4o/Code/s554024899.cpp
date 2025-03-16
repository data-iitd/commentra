#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    // Read two integers from the input
    int x = readInt();
    int y = readInt();
    
    // Define a vector containing three vectors, each representing a group of months with the same number of days
    int xt = -1, yt = -1;
    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
    
    // Iterate over the vector to determine which group each of the integers belongs to
    for (int i = 0; i < a.size(); i++) {
        for (int n : a[i]) {
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

// <END-OF-CODE>
