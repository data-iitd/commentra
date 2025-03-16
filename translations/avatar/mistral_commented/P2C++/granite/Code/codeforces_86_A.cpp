
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Take two integers as input and store them in vector 'l' and 'r' respectively
    vector<int> l, r;
    int temp;
    while (cin >> temp) {
        l.push_back(temp);
    }
    while (cin >> temp) {
        r.push_back(temp);
    }

    // Initialize current number to the last element of 'r'
    int curr = r.back();
    r.pop_back();

    // Initialize sum variable's' to 0
    int s = 0;

    // While 'curr' is not zero, perform the following operations
    while (curr) {
        // Increment the sum's' by 1
        s += 1;

        // Calculate the power of 10 raised to the value of's' and store it in 'first'
        int first = pow(10, s);

        // Calculate half of 'first' and store it in'second'
        int second = first / 2;

        // Initialize 'ans' with a negative value
        int ans = -1;

        // Iterate through the vector containing 'l', 'r', 'first', and'second'
        for (int i : {l.back(), r.back(), first, second}) {
            // If 'i' lies within the range of 'l' and 'r', update 'curr' and'rev'
            if (i >= l.back() && i <= r.back()) {
                curr = i;
                int rev = 0;
                // Reverse the digits of 'curr' and store it in'rev'
                while (curr) {
                    rev = rev * 10 + (9 - (curr % 10));
                    curr /= 10;
                }
                // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
                ans = max(ans, rev * curr);
            }
        }
        l.pop_back();
        r.pop_back();
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
