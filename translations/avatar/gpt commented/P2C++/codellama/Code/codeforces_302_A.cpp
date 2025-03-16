#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read two integers n and m from input
    int n, m;
    cin >> n >> m;
    
    // Count the number of '-' characters in the input string
    string s;
    cin >> s;
    int sa = count(s.begin(), s.end(), '-');
    
    // Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
    sa = min(n - sa, sa);
    
    // Initialize an empty list to store results
    string ss;
    
    // Loop m times to read pairs of integers a and b
    for (int i = 0; i < m; i++) {
        // Read two integers a and b from input
        int a, b;
        cin >> a >> b;
        
        // Calculate the difference b - a
        b -= a;
        
        // Check if b is odd and less than or equal to double the count of '-'
        // Append "1\n" to the results if true, otherwise append "0\n"
        ss += (b % 2 && b <= sa << 1) ? "1\n" : "0\n";
    }
    
    // Print the concatenated results from the list
    cout << ss;
    
    return 0;
}

