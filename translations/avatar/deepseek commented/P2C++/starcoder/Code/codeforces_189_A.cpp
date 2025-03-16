#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Take input from the user, which is expected to be a list of three integers
    int arr[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    
    // Assign the first integer in the input list to the variable 'length'
    int length = arr[0];
    
    // Sort the remaining three integers in ascending order and assign to 'arr'
    sort(arr + 1, arr + 4);
    
    // Check if 'length' is perfectly divisible by the largest integer in 'arr'
    if (length % arr[0] == 0) {
        // Print the quotient and return if true
        cout << length / arr[0] << endl;
        return 0;
    }
    
    // Initialize 'ans' to 0 for storing the maximum number of ribbons
    int ans = 0;
    
    // If the two smaller integers are equal, proceed with this block
    if (arr[0] == arr[1]) {
        int k = 0;
        // Iterate through possible combinations of the two smaller integers
        for (int i = 0; i <= length / arr[2]; i++) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                k = check / arr[0];
                ans = max(ans, k + i);
            }
        }
    } else {
        // If the two smaller integers are not equal, iterate through all three integers
        int k = 0;
        for (int i = 0; i <= length / arr[2]; i++) {
            for (int j = 0; j <= length / arr[1]; j++) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }
    
    // Print the maximum number of ribbons that can be cut and return
    cout << ans << endl;
    return 0;
}

