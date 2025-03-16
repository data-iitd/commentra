#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a single integer input
int num_inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers
vector<int> arr_inp() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

// Function to read a space-separated list of integers
vector<int> sp_inp() {
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }
    return arr;
}

int main() {
    // Read input from file (standard input in this case)
    vector<int> a;
    int n;
    cin >> n; // Read the number of elements
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the list of integers
    sort(a.begin(), a.end());

    // Find the largest number that leaves a remainder when divided by any number in the list
    cout << (any_of(a.begin(), a.end(), [&](int x) { return x % a[0] != 0; }) ? a[0] : -1) << endl;

    return 0;
}

// <END-OF-CODE>
