
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of pairs of integers to be processed
    int n;
    cin >> n;

    // Initialize an array to store the characters representing the actions
    vector<char> ch(n);

    // Initialize sums for two different actions
    int s1 = 0, s2 = 0;

    // Loop variables
    int i, j = 0, flag = 0, dif = 0;

    // Process each pair of integers
    for (i = 0; i < n; i++) {
        // Read the next pair of integers
        int x, y;
        cin >> x >> y;

        // Calculate temporary sums for the current iteration
        int temp1 = s1 + x;
        int temp2 = s2 + y;

        // Check if adding x to s1 keeps the difference within 500
        if (abs(temp1 - s2) <= 500) {
            s1 += x; // Update s1
            ch[j++] = 'A'; // Record the action 'A'
            continue; // Move to the next iteration
        }

        // Check if adding y to s2 keeps the difference within 500
        if (abs(temp2 - s1) <= 500) {
            s2 += y; // Update s2
            ch[j++] = 'G'; // Record the action 'G'
            continue; // Move to the next iteration
        }

        // If neither condition is met, set flag to indicate failure
        flag = 1;
        break; // Exit the loop
    }

    // Check if the loop was exited due to a failure condition
    if (flag == 1)
        cout << -1 << endl; // Output -1 to indicate failure
    else {
        // Convert the character array to a string and print the result
        string ans = "";
        for (int k = 0; k < j; k++) {
            ans += ch[k];
        }
        cout << ans << endl; // Output the recorded actions
    }

    return 0;
}
