
#include <bits/stdc++.h>
using namespace std;

// Define a debug function to print debug messages
// This function is used only when running the program in an IDE or terminal
void set_debug() {
    // Implement the debug function here
}

int main() {
    // Define input reading functions for single integer and string
    auto II = [&]() {
        int n;
        cin >> n;
        return n;
    };
    auto P = 100000007;
    auto INF = 1000000010;

    // Read input for two numbers 'a' and 'b'
    auto sa = II();
    auto sb = II();

    // Calculate the product of 'a' and 'b' and print the result
    cout << sa * sb / 100 << endl;

    return 0;
}

