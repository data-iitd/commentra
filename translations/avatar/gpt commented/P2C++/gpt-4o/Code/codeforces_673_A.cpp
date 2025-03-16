#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read an integer input which represents the number of elements in the array
    int n;
    cin >> n;

    // Read the next line of input and store it in a vector
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Check if the first element of the array is greater than 15
    if (arr[0] > 15) {
        // If true, print 15 as the output
        cout << 15 << endl;
    } else {
        // Iterate through the array starting from the second element
        for (int i = 1; i < arr.size(); i++) {
            // Check if the difference between the current and previous element is greater than 15
            if (arr[i] - arr[i - 1] > 15) {
                // If true, print the previous element plus 15 and exit the loop
                cout << arr[i - 1] + 15 << endl;
                break;
            }
            // If no break occurred, check the last element of the array
            if (i == arr.size() - 1) {
                if (arr[i] == 90 || arr[i] + 15 >= 90) {
                    // If the last element is 90 or adding 15 to it results in 90 or more, print 90
                    cout << 90 << endl;
                } else {
                    // Otherwise, print the last element plus 15
                    cout << arr[i] + 15 << endl;
                }
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
