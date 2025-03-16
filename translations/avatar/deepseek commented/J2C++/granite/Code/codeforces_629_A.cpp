

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num; // Read the size of the grid
    int counter = 0; // Counter for the number of 'C's
    int fine = 0; // Fine amount to be calculated
    vector < string > arr(num); // Vector to store the grid rows

    // Read num strings representing the grid rows
    for (int i = 0; i < num; i++) {
        string s;
        cin >> s;
        arr[i] = s;
    }

    // Calculate the fine for each column
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2; // Calculate the fine for the column
        counter = 0; // Reset the counter for the next column
    }

    // Calculate the fine for each row
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2; // Calculate the fine for the row
        counter = 0; // Reset the counter for the next row
    }

    // Print the total fine
    cout << fine << endl; // Print the total fine

    return 0;
}
