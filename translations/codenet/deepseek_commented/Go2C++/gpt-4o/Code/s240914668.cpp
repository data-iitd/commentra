#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; // Read the number of elements n.
    vector<int> a(n); // Create a vector to hold n integers.
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read n integers into the vector a.
    }

    int ans = 0; // Initialize ans to 0 to keep track of the number of segments.
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1; // Set l to i and r to i + 1.
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++; // Expand r as long as the condition holds.
        }
        ans++; // Increment ans after finding the segment.
        i = r; // Update i to r.
    }
    
    cout << ans << endl; // Output the number of segments ans.
    return 0; // End of the program.
}

// <END-OF-CODE>
