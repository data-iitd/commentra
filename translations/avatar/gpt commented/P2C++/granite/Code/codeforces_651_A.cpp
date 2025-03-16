
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << max(x + y - 3 + ((y - x) % 3 > 0), 0) << endl;
    return 0;
}

// Define a lambda function to read a single integer from input
auto num_inp = []() { int x; cin >> x; return x; };

// Define a lambda function to read a list of integers from input
auto arr_inp = []() { int n; cin >> n; vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i]; return arr; };

// Define a lambda function to read a space-separated list of integers from input
auto sp_inp = []() { int n; cin >> n; vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i]; return arr; };

// Define a lambda function to read a string from input
auto str_inp = []() { string s; cin >> s; return s; };

// Define a lambda function to read a single character from input
auto char_inp = []() { char c; cin >> c; return c; };

// Define a lambda function to read a single line from input
auto line_inp = []() { string s; getline(cin, s); return s; };

// Define a lambda function to read a single word from input
auto word_inp = []() { string s; cin >> s; return s; };

// Define a lambda function to read a single floating-point number from input
auto float_inp = []() { double x; cin >> x; return x; };

// Define a lambda function to read a single boolean from input
auto bool_inp = []() { bool x; cin >> x; return x; };

// Define a lambda function to read a single integer from input
auto num_inp = []() { int x; cin >> x; return x; };

// Define a lambda function to read a list of integers from input
auto arr_inp = []() { int n; cin >> n; vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i]; return arr; };

// Define a lambda function to read a space-separated list of integers from input
auto sp_inp = []() { int n; cin >> n; vector<int> arr(n); for (int i = 0; i < n; i++) cin >> arr[i]; return arr; };

// Define a lambda function to read a string from input
auto str_inp = []() { string s; cin >> s; return s; };

// Define a lambda function to read a single character from input
auto char_inp = []() { char c; cin >> c; return c; };

// Define a lambda function to read a single line from input
auto line_inp = []() { string s; getline(cin, s); return s; };

// Define a lambda function to read a single word from input
auto word_inp = []() { string s; cin >> s; return s; };

// Define a lambda function to read a single floating-point number from input
auto float_inp = []() { double x; cin >> x; return x; };

// Define a lambda function to read a single boolean from input
auto bool_inp = []() { bool x; cin >> x; return x; };