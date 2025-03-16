#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<vector<int>> menu;  // Initialize an empty list to store menu items
    int m, e;  // Initialize variables to store menu item and its value

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < 5; i++) {
        cin >> m;  // Take input from the user
        e = m % 10;  // Extract the last digit of the input and store it in e
        if (e == 0) {  // If the last digit is 0
            e = 10;  // Change it to 10 (to avoid zero as a value)
        }
        menu.push_back({m, e});  // Append a list containing the integer value of m and e to the menu
    }

    // Sort the menu based on the second element (e) of each sublist
    sort(menu.begin(), menu.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; });

    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop through the sorted menu starting from the second item
    for (int i = 1; i < menu.size(); i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += ceil(menu[i][0] / 10.0) * 10;
    }

    // Print the total cost, including the first item's original value
    cout << ans + menu[0][0] << endl;  // Add the first item's value to the accumulated cost and print the result

    return 0;
}

