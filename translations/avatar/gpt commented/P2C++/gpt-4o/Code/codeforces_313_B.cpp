#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the input string from the user
    string soz;
    cin >> soz;

    // Initialize a vector 'a' to store the cumulative count of consecutive characters
    // The size of 'a' is one more than the length of 'soz' to handle the base case
    vector<int> a(soz.length() + 1, 0);

    // Iterate through the string to fill the cumulative count array 'a'
    for (size_t i = 1; i < soz.length(); i++) {
        // Carry forward the previous count
        a[i] = a[i - 1];

        // If the current character is the same as the previous one, increment the count
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    // Read the number of queries from the user
    int n;
    cin >> n;

    // Initialize an empty vector to store the results of each query
    vector<int> arr;

    // Process each query
    for (int i = 0; i < n; i++) {
        // Read the start and end indices for the query
        int m, l;
        cin >> m >> l;

        // Calculate the number of consecutive characters between indices m and l
        // and append the result to the 'arr' vector
        arr.push_back(a[l - 1] - a[m - 1]);
    }

    // Print the results for each query
    for (int result : arr) {
        cout << result << endl;
    }

    return 0;
}

// <END-OF-CODE>
