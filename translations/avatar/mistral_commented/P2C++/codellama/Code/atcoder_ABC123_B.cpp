#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    // Initialize an empty vector called menu
    vector<vector<int>> menu;

    // Use a for loop to iterate 5 times
    for (int i = 0; i < 5; i++) {
        // Take user input and assign it to the variable m
        string m;
        cin >> m;

        // Extract the last character of the string m to determine the exponent e
        int e = m[m.length() - 1] - '0';

        // If e is 0, set it to 10
        if (e == 0) {
            e = 10;
        }

        // Append a list containing the integer value of m and the exponent e to the menu vector
        menu.push_back({stoi(m), e});
    }

    // Sort the menu vector based on the exponent value using the sort() method with a lambda function as the key
    sort(menu.begin(), menu.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });

    // Initialize a variable called ans to 0
    int ans = 0;

    // Use a for loop to iterate through the menu vector starting from the second element (index 1)
    for (int i = 1; i < menu.size(); i++) {
        // Calculate the number of full 10s that can be obtained by dividing the integer value by 10 and rounding up using the ceil() function from the math module
        int num_full_10s = ceil(menu[i][0] / 10.0);

        // Multiply this value by 10 and add it to the ans variable
        ans += num_full_10s * 10;
    }

    // Finally, print the sum of the first element in the menu vector (which is the initial number) and the value of ans
    cout << menu[0][0] + ans << endl;

    return 0;
}

