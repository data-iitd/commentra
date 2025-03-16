#include <iostream>
using namespace std;

// Define constants for the problem
const int MOD = 1e9 + 7;

int main() {
    // Initialize input and output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of test cases
    int t;
    cin >> t;
    
    // Process each test case
    while (t--) {
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
        long long low = 1;
        long long high = x + 1;
        long long ans = 1;
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
    
    return 0;
}

// <END-OF-CODE>
