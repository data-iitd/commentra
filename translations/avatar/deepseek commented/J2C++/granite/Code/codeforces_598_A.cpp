
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q; // Read the number of queries
    
    while (q--) {
        int n;
        cin >> n; // Read the number n for the current query
        long long s = 0; // Initialize the sum variable s
        
        int x = (int) (log2(n) + 1); // Calculate the position of the most significant bit of n
        x++; // Increment x by 1
        
        s = -1 * pow(2, x) + 2 + (long long) n * (long long) (n + 1) / 2 - pow(2, x); 
        // Calculate s using arithmetic operations and power functions
        
        cout << s << endl; // Print the result s for the current query
    }
    
    return 0;
}
