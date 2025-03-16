#include <iostream>
#include <vector>

using namespace std;

// FastReader class to handle fast input
class FastReader {
public:
    // Method to read the next integer from input
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

int main() {
    FastReader scan; // Create an instance of FastReader for input
    int t = 1; // Number of test cases (currently set to 1)
    
    while (t-- > 0) {
        // Read the number of elements in the array
        int n = scan.nextInt();
        vector<int> arr(n);
        
        // Populate the array with input values
        for (int i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
        }
        
        int prevWinner = 0; // Variable to track the previous winner
        
        // Iterate through the array to determine the winner for each element
        for (int i = 0; i < n; i++) {
            // Check if the current element is 1
            if (arr[i] == 1) {
                // If the previous winner is 0, set the previous winner to 2
                if (prevWinner == 0) {
                    prevWinner = 2;
                }
            }
            
            // Determine the winner based on the previous winner and the current element
            if (prevWinner == 2 || prevWinner == 0) {
                // If the previous winner is 2 or 0, check the parity of (arr[i] - 1)
                if ((arr[i] - 1) % 2 == 0) {
                    cout << 2 << endl; // Print winner 2
                    prevWinner = 2; // Update previous winner
                } else {
                    cout << 1 << endl; // Print winner 1
                    prevWinner = 1; // Update previous winner
                }
            } else {
                // If the previous winner is 1, check the parity of (arr[i] - 1)
                if ((arr[i] - 1) % 2 == 0) {
                    cout << 1 << endl; // Print winner 1
                    prevWinner = 1; // Update previous winner
                } else {
                    cout << 2 << endl; // Print winner 2
                    prevWinner = 2; // Update previous winner
                }
            }
        }
    }
    
    return 0;
}

// <END-OF-CODE>
