
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;  // Declaring string variable s
    int n;  // Declaring integer variable n
    cin >> s >> n;  // Taking input for string s and integer n

    int ans = 0;  // Initializing the answer variable to 0

    for (int i = 0; i < n; i++) {
        string x;  // Declaring string variable x
        cin >> x;  // Taking input for string x of length 2

        int a = 0, b = 0;  // Initializing counters a and b to 0

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == x[0])  // Checking if the character matches the first character of x
                a++;  // Incrementing the count for the first character
            else if (s[j] == x[1])  // Checking if the character matches the second character of x
                b++;  // Incrementing the count for the second character
            else {  // If the character does not match any of the two
                ans += min(a, b);  // Adding the minimum of a and b to ans
                a = b = 0;  // Resetting the counters a and b to 0
            }
        }

        ans += min(a, b);  // Adding the minimum of a and b to ans after the inner loop
    }

    cout << ans << endl;  // Printing the final answer

    return 0;
}
// END-OF-CODE