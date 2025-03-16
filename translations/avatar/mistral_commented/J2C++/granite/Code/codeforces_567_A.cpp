
#include <iostream> // Importingiostream for user input and output
#include <cmath> // Importingcmath for using the max and min functions

using namespace std;

int main() {
    int a; // Variable to store the size of the array
    cout << "Enter the size of the array: "; // Asking user for the size of the array
    cin >> a;

    int ar[a]; // Array to store the elements

    // Reading array elements from user input
    for (int i = 0; i < a; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> ar[i];
    }

    // Initializing variables for storing maximum and minimum differences
    int max = 0, min = 0;

    // Finding maximum and minimum differences between consecutive elements in the array
    for (int i = 0; i < a; i++) {
        // Finding maximum difference between current element and first element
        max = max(ar[i] - ar[0], ar[a - 1] - ar[i]);

        // Finding minimum difference between current element and previous element
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // For the first element, minimum difference is between current and next element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // For the last element, minimum difference is between current and previous element
        } else {
            min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        cout << min << " " << max << endl;
    }

    return 0;
}
