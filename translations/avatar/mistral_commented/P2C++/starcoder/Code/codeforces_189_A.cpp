#include <bits/stdc++.h>
using namespace std;

int main() {
    // Take input as a list of integers, where the first integer represents the length of the ribbon
    vector<int> arr;
    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    // Sort the next three elements of the list in ascending order
    sort(arr.begin() + 1, arr.begin() + 4);

    // Initialize an answer variable to keep track of the maximum number of pieces that can be cut
    int ans = 0;

    // If the first two elements of the sorted list are equal
    if (arr[1] == arr[2]) {
        // Initialize a variable k to keep track of the number of pieces required
        int k = 0;

        // Loop to find the maximum number of pieces that can be cut from the ribbon
        for (int i = 0; i <= arr[0] / arr[2]; i++) {
            // Check if the remaining length after subtracting i * arr[2] is divisible by arr[0]
            int check = arr[0] - i * arr[2];
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
        for (int i = 0; i <= arr[0] / arr[2]; i++) {
            for (int j = 0; j <= arr[0] / arr[1]; j++) {
                // Check if the remaining length after subtracting i * arr[2] and j * arr[1] is divisible by arr[0]
                int check = arr[0] - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    // If it is, update the answer and k
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }

    // Print the final answer
    cout << ans << endl;
    return 0;
}

