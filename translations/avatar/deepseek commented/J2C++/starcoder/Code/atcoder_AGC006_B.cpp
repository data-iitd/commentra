#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    print(x, n);
    return 0;
}

// Method to print based on the value of x and n
void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        cout << "No" << endl; // Print "No" if x is 1 or max
        return; // Exit the method
    }
    cout << "Yes" << endl; // Print "Yes" if x is within the valid range
    string sep = "\n"; // Get the system's line separator
    string ans = "";
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Generate a stream of numbers
        ans += to_string(i % max + 1) + sep; // Map each number to the required format
    }
    cout << ans; // Print the constructed string
}

