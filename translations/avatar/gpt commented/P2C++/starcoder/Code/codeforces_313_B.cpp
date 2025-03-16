#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read the input string from the user
    string soz;
    cin >> soz;

    // Initialize a list 'a' to store the cumulative count of consecutive characters
    // The length of 'a' is one more than the length of'soz' to handle the base case
    int a[soz.length() + 1];
    for (int i = 0; i < soz.length() + 1; i++) {
        a[i] = 0;
    }

    // Iterate through the string to fill the cumulative count array 'a'
    for (int i = 1; i < soz.length(); i++) {
        // Carry forward the previous count
        a[i] = a[i - 1];

        // If the current character is the same as the previous one, increment the count
        if (soz[i - 1] == soz[i]) {
            a[i] += 1;
        }
    }

    // Read the number of queries from the user
    int n;
    cin >> n;

    // Initialize an empty list to store the results of each query
    int arr[n];

    // Process each query
    for (int i = 0; i < n; i++) {
        // Read the start and end indices for the query
        string m, l;
        cin >> m >> l;

        // Calculate the number of consecutive characters between indices m and l
        // and append the result to the 'arr' list
        arr[i] = a[stoi(l) - 1] - a[stoi(m) - 1];
    }

    // Print the results for each query
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

