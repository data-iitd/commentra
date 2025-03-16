
#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Define constants for the problem
    const int N = 1e5 + 5; 
    const int MOD = 1e9 + 7; 

    // Initialize scanner for input and print writer for output
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    // Read the number of test cases
    int t; 
    cin >> t; 

    // Process each test case
    while (t-- > 0) { 
        // Read input values for each test case
        long long n, a, b; 
        cin >> n >> a >> b; 

        // Check if n is less than a, if so, output "No"
        if (n < a) { 
            cout << "No\n"; 
            continue; 
        } 

        // If a equals b, check if n is a multiple of a
        if (a == b) { 
            if (n % a == 0) { 
                cout << "Yes\n"; 
            } else { 
                cout << "No\n"; 
            } 
            continue; 
        } 

        // Calculate the maximum number of a's that can fit into b
        long long x = b / (b - a); 

        // If n is greater than x * a, output "Yes"
        if (n > x * a) { 
            cout << "Yes\n"; 
            continue; 
        } 

        // Binary search to find the largest mid such that mid * a < n
        long long low = 1, high = x + 1, ans = 1; 
        while (low <= high) { 
            long long mid = (low + high) / 2; 

            // Adjust the search range based on the condition
            if (mid * a < n) { 
                low = mid + 1; 
            } else { 
                ans = mid; 
                high = mid - 1; 
            } 
        } 

        // Check the final conditions to determine output
        if (n > (ans - 1) * b && n < ans * a) { 
            cout << "No\n"; 
        } else { 
            cout << "Yes\n"; 
        } 
    } 

    // Close the output writer
    return 0; 
}

