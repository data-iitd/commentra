#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    // Define a lambda function to read an integer input
    auto num_inp = []() { int n; cin >> n; return n; };

    // Define a lambda function to read a list of integers from input
    auto arr_inp = []() {
        vector<int> arr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        return arr;
    };

    // Define a lambda function to read a space-separated list of integers as a map object
    auto sp_inp = []() {
        map<int, int> m;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        return m;
    };

    // Read the input from the first line of the standard input, sort it, and convert it to a list of integers
    vector<int> a = arr_inp();
    sort(a.begin(), a.end());

    // Check if any element in the list 'a' is not divisible by the first element of 'a'
    // If all elements are divisible, print the first element; otherwise, print -1
    cout << (all_of(a.begin(), a.end(), [&](int x) { return x % a[0] == 0; }) ? a[0] : -1) << endl;

    return 0;
}

