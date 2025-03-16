#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper functions for simplifying input process
int num_inp() {
    int n;
    cin >> n;
    return n;
}

vector<int> arr_inp() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

vector<int> sp_inp() {
    vector<int> arr;
    int n;
    while (cin >> n) {
        arr.push_back(n);
    }
    return arr;
}

string str_inp() {
    string s;
    cin >> s;
    return s;
}

int main() {
    // Define variables x and y by unpacking the input
    int x, y;
    cin >> x >> y;

    // Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;

    return 0;
}

// <END-OF-CODE>
