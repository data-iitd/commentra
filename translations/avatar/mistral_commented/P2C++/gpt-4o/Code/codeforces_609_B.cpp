#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to read input as a vector of integers
vector<int> input() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    return vec;
}

int main() {
    // Read number of elements 'n' and size 'm' of the list 'lst'
    int n, m;
    cin >> n >> m;

    // Read the list 'lst'
    vector<int> lst = input();

    // Initialize an empty unordered_map 'l' to store the frequency of each element
    unordered_map<int, int> l;

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; ++i) {
        // Increment the frequency of the current element in the unordered_map 'l'
        l[lst[i]]++;
    }

    // Initialize result variable 'res' to 0
    long long res = 0;

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; ++i) {
        // If the frequency of the current element in the unordered_map 'l' is greater than 1
        if (l[lst[i]] > 1) {
            // Calculate the number of elements that have a smaller frequency than the current element
            // and add it to the result variable 'res'
            res += n - i - l[lst[i]];
            // Decrease the frequency of the current element in the unordered_map 'l' by 1
            l[lst[i]]--;
        } else {
            // If the frequency of the current element in the unordered_map 'l' is equal to 1
            // Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
            res += n - i - 1;
        }
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
