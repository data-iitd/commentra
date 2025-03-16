#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Step 1: Take two integers as input and assign them to x and y.
    int x, y;
    cin >> x >> y;

    // Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;

    // Step 3: Define lambda functions for taking different types of inputs.
    auto num_inp = []() { int n; cin >> n; return n; };
    auto arr_inp = []() { 
        int n; cin >> n; 
        vector<int> arr(n); 
        for (int &i : arr) cin >> i; 
        return arr; 
    };
    auto sp_inp = []() { 
        int a, b; cin >> a >> b; 
        return make_pair(a, b); 
    };
    auto str_inp = []() { 
        string s; cin >> s; 
        return s; 
    };

    return 0;
}

// <END-OF-CODE>
