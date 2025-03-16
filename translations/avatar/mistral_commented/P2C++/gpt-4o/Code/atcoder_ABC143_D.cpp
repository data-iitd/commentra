#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements 'n' and a list 'l' of 'n' integers
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    // Sort the list 'l' in ascending order
    sort(l.begin(), l.end());

    // Initialize an answer variable 'ans' to zero
    long long ans = 0;

    // Iterate through each pair of indices 'i' and 'j' in the list 'l'
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
            int a = l[i];
            int b = l[j];

            // Use lower_bound to find the index 'right' where an element greater than 'a+b' is present
            auto right_it = lower_bound(l.begin(), l.end(), a + b);
            int right = right_it - l.begin();

            // Use upper_bound to find the index 'left' where the smallest element greater than 'max(a-b, b-a)' is present
            auto left_it = upper_bound(l.begin(), l.end(), max(a - b, b - a));
            int left = left_it - l.begin();

            // Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
            long long tmp = max(0LL, right - left);

            // Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
            if (left <= i && i < right) {
                tmp -= 1;
            }
            if (left <= j && j < right) {
                tmp -= 1;
            }

            // Add the temporary answer 'tmp' to the final answer 'ans'
            ans += tmp;
        }
    }

    // Print the final answer 'ans' divided by three
    cout << ans / 3 << endl;

    return 0;
}

// <END-OF-CODE>
