#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Define lambda functions for input handling
    // num_inp: takes a single input as an integer
    // arr_inp: takes a list input where each element is an integer
    // sp_inp: takes a list input where each element is an integer, space-separated

    auto num_inp = [&]() {
        int x;
        cin >> x;
        return x;
    };

    auto arr_inp = [&]() {
        vector<int> a;
        int x;
        while (cin >> x) {
            a.push_back(x);
        }
        return a;
    };

    auto sp_inp = [&]() {
        vector<int> a;
        int x;
        while (cin >> x) {
            a.push_back(x);
        }
        return a;
    };

    // Read input from file instead of user input
    vector<int> a = arr_inp();
    sort(a.begin(), a.end());

    // Find the largest number that leaves a remainder when divided by any number in the list
    cout << (any_of(a.begin(), a.end(), [&](int x) { return a[0] % x == 0; }) ? a[0] : -1) << endl;

    return 0;
}

