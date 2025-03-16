
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<int> menu;  // Initialize an empty vector to store menu items

    // Loop to collect 5 menu items from user input
    for (int i = 0; i < 5; i++) {
        string m;  // Declare a string variable to store the input
        cin >> m;  // Take input from the user
        int e = m[m.length() - 1] - '0';  // Extract the last character of the input and convert it to an integer
        if (e == 0)  // If the last digit is 0
            e = 10;  // Change it to 10 (to avoid zero as a value)
        menu.push_back(e);  // Append the integer value of e to the menu
    }

    // Sort the menu based on the second element (e) of each sublist
    sort(menu.begin(), menu.end());

    int ans = 0;  // Initialize a variable to accumulate the total cost

    // Loop through the sorted menu starting from the second item
    for (int i = 1; i < menu.size(); i++) {
        // Calculate the cost for each item, rounding up to the nearest multiple of 10
        ans += ceil(menu[i] / 10.0) * 10;
    }

    // Print the total cost, including the first item's original value
    cout << ans + menu[0] << endl;  // Add the first item's value to the accumulated cost and print the result

    return 0;
}

