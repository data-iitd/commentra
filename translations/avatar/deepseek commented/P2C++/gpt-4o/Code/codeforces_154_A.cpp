#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;  // Taking input string s
    cin >> s;  // Input for string s
    int n;     // Taking integer input n
    cin >> n;  // Input for integer n
    int ans = 0;  // Initializing the answer variable to 0

    // Loop runs n times
    for (int i = 0; i < n; i++) {
        string x;  // Taking input for string x of length 2
        cin >> x;  // Input for string x
        int a = 0, b = 0;  // Initializing counters a and b to 0

        // Iterating over each character in the string s
        for (char j : s) {
            if (j == x[0]) {  // Checking if the character matches the first character of x
                a++;  // Incrementing the count for the first character
            } else if (j == x[1]) {  // Checking if the character matches the second character of x
                b++;  // Incrementing the count for the second character
            } else {  // If the character does not match any of the two
                ans += min(a, b);  // Adding the minimum of a and b to ans
                a = 0;  // Resetting the counters a and b to 0
                b = 0;
            }
        }

        ans += min(a, b);  // Adding the minimum of a and b to ans after the inner loop
    }

    cout << ans << endl;  // Printing the final answer
    return 0;
}  // <END-OF-CODE>
