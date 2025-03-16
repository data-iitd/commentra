
#include <iostream>  // Include the necessary header file for input/output operations
#include <cmath>  // Include the necessary header file for mathematical functions
#include <vector>  // Include the necessary header file for working with vectors

using namespace std;  // Use the standard namespace for input/output operations

int main() {
    vector<vector<int>> menu;  // Declare a vector to store menu items as vectors of integers
    int e;  // Declare a variable to store the extracted last digit of a menu item

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < 5; i++) {
        string m;  // Declare a string variable to store the user input
        cin >> m;  // Take input from the user
        e = stoi(m.substr(m.length() - 1));  // Extract the last character of the input and convert it to an integer
        if (e == 0) {  // If the last digit is 0
            e = 10;  // Change it to 10 (to avoid zero as a value)
        }
        menu.push_back({stoi(m), e});  // Append a vector containing the integer value of m and e to the menu
    }

    // Sort the menu based on the second element (e) of each vector
    sort(menu.begin(), menu.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop through the sorted menu starting from the second item
    for (int i = 1; i < menu.size(); i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += ceil(menu[i][0] / 10.0) * 10;
    }

    // Print the total cost, including the first item's original value
    cout << ans + menu[0][0] << endl;  // Add the first item's value to the accumulated cost and print the result

    return 0;  // Return 0 to indicate successful execution of the program
}
