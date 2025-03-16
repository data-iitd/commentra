#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Initialize an array of strings called divide
string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    // Declare a string variable called S and read a string from the standard input
    string S;
    cin >> S;

    // Reverse the string S and also reverse each string in the divide array
    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());

    // Initialize a boolean variable called can to true
    bool can = true;

    // Iterate through each character in the string S
    for (int i = 0; i < S.size();) {
        // Initialize a boolean variable called can2 to false
        bool can2 = false;

        // Iterate through each string in the divide array
        for (int j = 0; j < 4; ++j) {
            // Get the string d from the divide array
            string d = divide[j];

            // Check if the substring of S starting from the current index i and having the same size as d is equal to d
            if (S.substr(i, d.size()) == d) {
                // If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
                can2 = true;
                i += d.size();
            }
        }

        // If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
        if (!can2) {
            can = false;
            break;
        }
    }

    // Output "YES" if can is true, otherwise output "NO"
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}
