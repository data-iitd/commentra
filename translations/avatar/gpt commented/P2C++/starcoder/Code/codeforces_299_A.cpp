#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Define a lambda function to read an integer input
    auto num_inp = [&]() {
        int x;
        cin >> x;
        return x;
    };

    // Define a lambda function to read a list of integers from input
    auto arr_inp = [&]() {
        int x;
        vector<int> v;
        while (cin >> x) {
            v.push_back(x);
        }
        return v;
    };

    // Define a lambda function to read a space-separated list of integers as a map object
    auto sp_inp = [&]() {
        int x;
        map<int, int> m;
        while (cin >> x) {
            m[x]++;
        }
        return m;
    };

    // Read the input from the first line of the standard input, sort it, and convert it to a list of integers
    vector<int> a = arr_inp();
    sort(a.begin(), a.end());

    // Check if any element in the list 'a' is not divisible by the first element of 'a'
    // If all elements are divisible, print the first element; otherwise, print -1
    cout << (any_of(a.begin(), a.end(), [&](int x) { return x % a[0]; })? a[0] : -1) << endl;

    return 0;
}

