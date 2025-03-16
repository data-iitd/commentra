#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
using namespace std;

int checkNo(const vector<int>& brr) { // Helper function to count the number of 1s in an array
    int val = 0;
    for (int i : brr) {
        if (i == 1) {
            ++val;
        }
    }
    return val;
}

int main() {
    int n;
    cin >> n; // Reading the size of the array
    vector<int> arr(n); // Declaring and initializing the array

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Reading the elements of the array
    }

    int max = INT_MIN; // Initializing max to the minimum possible integer value

    for (int i = 0; i < n; i++) { // Iterating over all possible starting points of subarrays
        for (int j = i; j < n; j++) { // Iterating over all possible ending points of subarrays
            vector<int> brr = arr; // Copying the elements of arr to brr

            for (int k = i; k <= j; k++) { // Flipping the elements in the current subarray
                brr[k] = (brr[k] == 0) ? 1 : 0; // Flipping 0 to 1 and 1 to 0
            }

            int count = checkNo(brr); // Counting the number of 1s in the modified subarray

            if (count > max) {
                max = count; // Updating max if the current count is greater
            }
        }
    }

    if (n == 1) { // Handling the special case of a single element array
        if (arr[0] == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        cout << max << endl; // Printing the maximum count of 1s found
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
