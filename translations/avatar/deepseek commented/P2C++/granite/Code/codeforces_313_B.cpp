

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string soz;
    cin >> soz;  // Take a string input from the user
    int a[soz.length() + 1] = {0};  // Initialize an array 'a' with zeros, with a length of soz.length() + 1

    // Iterate over the string from index 1 to soz.length() - 1
    for (int i = 1; i < soz.length(); i++) {
        a[i] = a[i - 1];  // Set 'a[i]' to the value of 'a[i - 1]'
        if (soz[i - 1] == soz[i])  // If the characters at positions 'i - 1' and 'i' are the same
            a[i] += 1;  // Increment 'a[i]' by 1
    }

    int n;
    cin >> n;  // Take an integer input from the user
    vector<int> arr;  // Initialize an empty vector 'arr'

    // Iterate 'n' times
    for (int i = 0; i < n; i++) {
        int m, l;
        cin >> m >> l;  // Take two inputs'm' and 'l'
        arr.push_back(a[l - 1] - a[m - 1]);  // Append the difference 'a[l - 1] - a[m - 1]' to 'arr'
    }

    // Print each element in 'arr'
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;  // Print the element at index 'i' in 'arr'
    }

    return 0;
}
