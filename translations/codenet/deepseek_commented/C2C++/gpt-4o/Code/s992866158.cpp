#include <iostream> // Include necessary headers
using namespace std;

int main() {
    int n, k, cnt; // Declare necessary variables

    cin >> n >> k; // Read input values
    cnt = 0; // Initialize the count variable
    while (n--) { // Use a while loop to read each height
        int h;

        cin >> h; // Read each height
        if (h >= k) // Check if the height is suitable
            cnt++; // Increment the count if the height is greater than or equal to k
    }
    cout << cnt << endl; // Print the final count
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
