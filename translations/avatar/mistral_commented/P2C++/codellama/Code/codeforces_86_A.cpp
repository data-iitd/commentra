#include <iostream>
using namespace std;

int main()
{
    // Take two integers as input and store them in 'l' and 'r' respectively
    int l, r;
    cin >> l >> r;

    // Initialize current number to 'r'
    int curr = r;

    // Initialize sum variable 's' to 0
    int s = 0;

    // While 'curr' is not zero, perform the following operations
    while (curr)
    {
        // Increment the sum 's' by 1
        s += 1;

        // Calculate the power of 10 raised to the value of 's' and store it in 'first'
        int first = 10 ** s;

        // Calculate half of 'first' and store it in 'second'
        int second = first / 2;

        // Initialize 'ans' with a negative value
        int ans = -1;

        // Iterate through the list containing 'l', 'r', 'first', and 'second'
        for (int i = l; i <= r; i++)
        {
            // If 'i' lies within the range of 'l' and 'r', update 'curr' and 'rev'
            if (i >= l && i <= r)
            {
                curr = i;
                string rev = "";

                // Reverse the digits of 'curr' and store it in 'rev'
                for (int k = 0; k < to_string(curr).length(); k++)
                {
                    rev += to_string(9 - (curr % 10));
                    curr /= 10;
                }

                // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
                ans = max(ans, stoi(rev) * i);
            }
        }
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

