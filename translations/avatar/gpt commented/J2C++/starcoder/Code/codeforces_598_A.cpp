#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int q;
    cin >> q;
    while (q-- > 0) {
        // Reading the integer n for the current test case
        int n;
        cin >> n;
        
        // Initializing a variable to store the result
        long long s = 0;
        
        // Calculating the highest power of 2 less than or equal to n
        int x = (int) (log2(n));
        x++;
        
        // Calculating the final result using the derived formula
        s = -1 * (long long) pow(2, x) + 2 + ((long long) n * (long long) (n + 1)) / 2 - (long long) pow(2, x);
        
        // Printing the result for the current test case
        cout << s << endl;
    }
    return 0;
}

