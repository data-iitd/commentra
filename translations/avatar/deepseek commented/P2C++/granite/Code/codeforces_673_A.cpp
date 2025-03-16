
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;  // Take input for the number of elements in the array
    vector<int> arr(n);  // Create a vector to store the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Take input for the array elements
    }

    // Check if the first element of the array is greater than 15
    if (arr[0] > 15) {
        cout << 15 << endl;  // If true, print 15
    } else {
        int i = 1;
        while (i < n) {
            // Check if the difference between the current and previous element is greater than 15
            if (arr[i] - arr[i - 1] > 15) {
                cout << arr[i - 1] + 15 << endl;  // If true, print the previous element plus 15 and break the loop
                break;
            }
            i++;
        }
        if (i == n) {
            // If the loop completes without breaking
            if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
                cout << 90 << endl;  // If the last element is 90 or adding 15 to the last element is >= 90, print 90
            } else {
                cout << arr[n - 1] + 15 << endl;  // Otherwise, print the last element plus 15
            }
        }
    }

    return 0;
}
