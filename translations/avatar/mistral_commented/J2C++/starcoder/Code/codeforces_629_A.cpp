#include <bits/stdc++.h>

using namespace std;

int main() {
    // Reading the number of strings 'num' from the user input
    int num;
    cin >> num;

    // Initializing an array of strings 'arr' with a size equal to 'num'
    string arr[num];

    // Reading each string's' from the user input and adding it to the array 'arr'
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    // Initializing two variables 'counter' and 'fine'
    int counter = 0;
    int fine = 0;

    // The first nested loop to iterate through each character in each string
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            // Checking if the character at position (i,k) in the string at index 'i' is 'C'
            if (arr[i][k] == 'C') {
                // Incrementing the counter variable
                counter++;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) / 2;
        // Resetting the counter variable for the next string
        counter = 0;
    }

    // The second nested loop to iterate through each character in each string again
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            // Checking if the character at position (i,k) in the string at index 'k' is 'C'
            if (arr[k][i] == 'C') {
                // Incrementing the counter variable
                counter++;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) / 2;
        // Resetting the counter variable for the next string
        counter = 0;
    }

    // Printing the final result 'fine'
    cout << fine << endl;

    // Closing the main method
    return 0;
}

