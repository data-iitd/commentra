#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Read two integers from input and assign them to x and y
    int x, y;
    cin >> x >> y;

    // Calculate the maximum value based on the formula and print it
    // The formula computes x + y - 3 and adjusts based on the difference between y and x
    // It ensures the result is not negative by taking the maximum with 0
    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;

    // Define a lambda function to read a single integer from input
    auto num_inp = []() {
        int num;
        cin >> num;
        return num;
    };

    // Define a lambda function to read a list of integers from input
    auto arr_inp = []() {
        int n;
        cin >> n; // Read the size of the array
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        return arr;
    };

    // Define a lambda function to read a space-separated list of integers from input
    auto sp_inp = []() {
        vector<int> arr;
        int num;
        while (cin >> num) {
            arr.push_back(num);
        }
        return arr;
    };

    // Define a lambda function to read a string from input
    auto str_inp = []() {
        string str;
        cin >> str;
        return str;
    };

    return 0;
}

// <END-OF-CODE>
