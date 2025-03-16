#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Take input string 'soz' from the user
    string soz;
    cin >> soz;

    // Initialize a vector 'a' of size 'len(soz)+1' with zeros
    vector<int> a(soz.length() + 1, 0);

    // Iterate through the string 'soz' starting from index 1
    for (int i = 1; i < soz.length(); i++) {
        // Assign the value of the previous index to the current index
        a[i] = a[i - 1];

        // If the current character is same as the previous character, increment the count
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    // Take the number of test cases 'n' as input
    int n;
    cin >> n;

    // Initialize an empty vector 'arr' to store the differences
    vector<int> arr;

    // Iterate through the test cases
    for (int i = 0; i < n; i++) {
        // Take two integers 'm' and 'l' as input, separated by a space
        int m, l;
        cin >> m >> l;

        // Calculate the difference between the count at index 'l' and index 'm'
        arr.push_back(a[l - 1] - a[m - 1]);
    }

    // Iterate through the vector 'arr' and print each difference
    for (int i : arr) {
        cout << i << endl;
    }

    return 0;
}

// <END-OF-CODE>
