
#include <iostream> // Importing iostream for input and output operations
#include <algorithm> // Importing algorithm for finding maximum and minimum values

using namespace std;

int main() {
    int a; // Declaring the size of the array
    cin >> a; // Reading the size of the array from the user
    int ar[a]; // Initializing the array with the size read from the user
    int max = 0, min = 0; // Initializing max and min to 0

    // Filling the array with integers read from the user
    for (int i = 0; i < a; i++) {
        cin >> ar[i];
    }

    // Calculating the minimum and maximum differences between consecutive elements of the array
    for (int i = 0; i < a; i++) {
        max = max(ar[i] - ar[0], ar[a - 1] - ar[i]); // Calculating the maximum difference
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // Calculating the minimum difference for the first element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // Calculating the minimum difference for the last element
        } else {
            min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // Calculating the minimum difference for other elements
        }
        cout << min << " " << max << endl; // Displaying the minimum and maximum differences
    }
    return 0;
}
