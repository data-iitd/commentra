#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cutRibbon() {
    // Function to find the maximum number of pieces that can be cut from a ribbon of given length

    // Take input as a list of integers, where the first integer represents the length of the ribbon
    vector<int> arr;
    int input;
    while (cin >> input) {
        arr.push_back(input);
    }

    // Assign the length of the ribbon to a variable
    int length = arr[0];

    // Sort the next three elements of the list in ascending order
    sort(arr.begin() + 1, arr.begin() + 4);

    // Check if the length of the ribbon is divisible by the first element of the sorted list
    if (length % arr[0] == 0) {
        // If it is, print the number of pieces required and return
        cout << length / arr[0] << endl;
        return;
    }

    // Initialize an answer variable to keep track of the maximum number of pieces that can be cut
    int ans = 0;

    // If the first two elements of the sorted list are equal
    if (arr[0] == arr[1]) {
        // Initialize a variable k to keep track of the number of pieces required
        int k = 0;

        // Loop to find the maximum number of pieces that can be cut from the ribbon
        for (int i = 0; i <= length / arr[2]; ++i) {
            // Check if the remaining length after subtracting i * arr[2] is divisible by arr[0]
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                // If it is, update the answer and k
                k = check / arr[0];
                ans = max(ans, k + i);
            }
        }
    }
    // If the first two elements of the sorted list are not equal
    else {
        // Initialize a variable k to keep track of the number of pieces required
        int k = 0;

        // Double loop to find the maximum number of pieces that can be cut from the ribbon
        for (int i = 0; i <= length / arr[2]; ++i) {
            for (int j = 0; j <= length / arr[1]; ++j) {
                // Check if the remaining length after subtracting i * arr[2] and j * arr[1] is divisible by arr[0]
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    // If it is, update the answer and k
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }

    // Print the final answer and return
    cout << ans << endl;
}

int main() {
    cutRibbon();
    return 0;
}
