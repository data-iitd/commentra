#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n); // Initialize array a
        vector<int> b(n, 0); // Initialize array b to all zeros
        int s = -1; // Initialize the counter s to -1

        // Read n integers into array a
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int tem = 1; // Initialize tem to 1
        int q = 0; // Initialize q to 0

        // Enter a while loop that continues until q equals n
        while (q != n) {
            s++; // Increment the counter s

            // If tem is 1, process elements from the start of a to the end
            if (tem == 1) {
                for (int i = 0; i < n; i++) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1; // Mark the element as processed
                        q++; // Increment the processed element counter
                    }
                }
                tem = 0; // Toggle tem to 0
            } 
            // If tem is 0, process elements from the end of a to the start
            else {
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] <= q && b[i] == 0) {
                        b[i] = 1; // Mark the element as processed
                        q++; // Increment the processed element counter
                    }
                }
                tem = 1; // Toggle tem to 1
            }
        }

        // Print the value of s
        cout << s << endl;
    }
    return 0;
}

// <END-OF-CODE>
