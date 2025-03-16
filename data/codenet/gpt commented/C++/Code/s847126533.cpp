#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to check if it is possible to distribute weights
bool check(int n, int wei, vector<int> book) {
    int tmp = wei; // Temporary variable to hold the remaining weight
    n--; // Decrease the number of available books by one
    for(int i = 0; i < book.size(); i++) {
        // If the current weight exceeds the available weight
        if(tmp < book[i]) {
            // If there are still books left to use
            if(n > 0) {
                n--; // Use one book
                tmp = wei; // Reset the temporary weight to the original weight
                // Check again if the current weight exceeds the available weight
                if(tmp < book[i])
                    return false; // Not possible to distribute
            } else {
                return false; // No books left to use
            }
        }
        // Deduct the current book's weight from the temporary weight
        tmp -= book[i];
    }
    return true; // Successfully distributed the weights
}

int main() {
    int m, n; // m: maximum weight, n: number of books
    // Read input until m is zero
    for(; cin >> m >> n, m;) {
        vector<int> book; // Vector to store the weights of the books
        // Read the weights of the books
        for(int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp; // Read each book's weight
            book.push_back(tmp); // Add weight to the vector
        }

        /*
        // Uncomment this block to check for multiple weight distributions
        while(true) {
            int tmp;
            cin >> tmp; // Read weight to check
            if(check(m, tmp, book))
                cout << "YES" << endl; // Possible distribution
            else
                cout << "NO" << endl; // Not possible distribution
        }
        */

        int l = 0; // Lower bound for binary search
        int r = 1500000; // Upper bound for binary search
        int ans; // Variable to store the answer
        // Perform binary search to find the maximum weight that can be distributed
        while(l < r) {
            // Check if the middle weight can be distributed
            if(check(m, (l + r) / 2, book)) {
                ans = (l + r) / 2; // Update answer
                // If the upper bound equals the middle, break the loop
                if(r == (l + r) / 2)
                    break;
                r = (l + r) / 2; // Move the upper bound down
            } else {
                // If the lower bound equals the middle, break the loop
                if(l == (l + r) / 2)
                    break;
                l = (l + r) / 2; // Move the lower bound up
            }
        }
        cout << ans << endl; // Output the maximum weight that can be distributed
    }
}
