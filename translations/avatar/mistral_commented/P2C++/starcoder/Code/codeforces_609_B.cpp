#include <bits/stdc++.h>
using namespace std;

// Function to read input as a list of integers
vector<int> _input() {
    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    return lst;
}

// Function to calculate the number of pairs of elements with smaller frequency than the current element
int countPairs(vector<int> &lst, int n) {
    // Initialize a dictionary 'l' to store the frequency of each element
    unordered_map<int, int> l;
    // Initialize result variable'res' to 0
    int res = 0;
    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the current element is not already present in the dictionary 'l'
        if (l.find(lst[i]) == l.end()) {
            // Add the current element to the dictionary 'l' with a frequency of 1
            l[lst[i]] = 1;
        }
        // If the current element is already present in the dictionary 'l'
        else {
            // Increment the frequency of the current element in the dictionary 'l'
            l[lst[i]] += 1;
        }
    }
    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the frequency of the current element in the dictionary 'l' is greater than 1
        if (l[lst[i]] > 1) {
            // Calculate the number of elements that have a smaller frequency than the current element
            // and add it to the result variable'res'
            res += n - i - l[lst[i]];
            // Decrease the frequency of the current element in the dictionary 'l' by 1
            l[lst[i]] -= 1;
        }
        // If the frequency of the current element in the dictionary 'l' is equal to 1
        else {
            // Calculate the number of elements that have not been processed yet and add it to the result variable'res'
            res += n - i - 1;
        }
    }
    // Return the final result
    return res;
}

// Driver Code
int main() {
    // Read number of elements 'n' and size'm' of the list 'lst'
    int n, m = _input()[0];
    // Read the list 'lst'
    vector<int> lst = _input();
    // Print the final result
    cout << countPairs(lst, n) << endl;
    return 0;
}

