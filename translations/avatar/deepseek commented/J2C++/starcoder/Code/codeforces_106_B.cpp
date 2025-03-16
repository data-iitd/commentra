
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initialize variables to store the number of elements and the best index
    int n, ans = 500;
    // Initialize variables to store the minimum price and the best index
    int ansprice = 20000;
    // Initialize a 2D array to store the elements
    int vec[500][4];
    // Initialize Scanner to read input from standard input
    cin >> n;
    // Read the elements into the 2D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> vec[i][j];
        }
    }
    // Loop through each element to find the best one
    for (int i = 0; i < n; i++) {
        int fl = 1; // Flag to check if the element is dominated
        // Compare the current element with every other element
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                fl = 0; // The element is dominated
            }
        }
        // If the element is not dominated, check its price
        if (fl == 1) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the minimum price
                ans = i + 1; // Update the best index
            }
        }
    }
    // Output the index of the best element
    cout << ans << endl;
    return 0;
}

