#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Reading the number of test cases

    vector<int> a(n + 1);  // Creating a vector 'a' of size 'n+1'
    vector<int> b(n + 1);  // Creating a vector 'b' of size 'n+1'
    vector<int> num(n + 1);  // Creating a vector 'num' of size 'n+1'
    vector<bool> st(n + 1, false);  // Creating a boolean vector 'st' of size 'n+1' initialized to false

    for (int i = 1; i <= n; i++) {  // Loop to read the elements of vectors 'a' and 'b'
        cin >> a[i];
        cin >> b[i];
    }

    string ss;  // Initializing an empty string 'ss' to store the final answer
    int ans = 0;  // Initializing an integer variable 'ans' to store the maximum length of the answer

    for (int i = 1; i <= n; i++) {  // Loop to find the longest chain of numbers
        if (a[i] == 1) {  // If the current number 'i' in vector 'a' is 1
            st[i] = true;  // Mark the current number as visited
            string sb;  // Creating a string 'sb' to store the answer
            int x = b[i];  // Assigning the value of 'b[i]' to 'x'
            string sss = to_string(i);  // Converting the current number 'i' to string
            reverse(sss.begin(), sss.end());  // Reversing the string 'sss'
            sb += " " + sss;  // Appending the reversed string of 'sss' to 'sb'
            int s = 1;  // Initializing an integer variable 's' to 1

            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {  // Loop to traverse the graph
                sss = to_string(x);  // Converting the current number 'x' to string
                reverse(sss.begin(), sss.end());  // Reversing the string 'sss'
                sb += " " + sss;  // Appending the reversed string of 'sss' to 'sb'
                st[x] = true;  // Marking the current number 'x' as visited
                x = b[x];  // Assigning the value of 'b[x]' to 'x'
                s++;  // Incrementing the length of the current chain
            }

            if (s > ans) {  // If the length of the current chain is greater than the current maximum length
                ans = s;  // Updating the maximum length
                reverse(sb.begin(), sb.end());  // Reversing the string 'sb'
                ss = sb;  // Updating the final answer
            }
        }
    }

    cout << ans << endl;  // Printing the maximum length of the longest chain
    cout << ss << endl;  // Printing the longest chain as a string

    return 0;
}

// <END-OF-CODE>
