#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i = 1, k = 0, p = 1;
    bool flag = true;
    vector<int> a(1000, 0);

    // Step 5: Read the value of n from the user input
    cin >> n;
    i = 0;

    // Step 6: Enter a while loop that continues until k is less than or equal to n
    while (k <= n) {
        // Step 7: Update the value of i by adding k to it
        i += k;

        // Step 8: Adjust the value of i if it is greater than or equal to n
        if (i >= n) {
            while (!(i < n))
                i -= n;
        }

        // Step 9: Increment the value of a[i] by 1
        ++a[i];

        // Step 10: Increment the value of k by 1
        ++k;
    }

    // Step 11: Enter a for loop to check if any value in the array a is 0
    for (i = 0; i < n; ++i)
        if (a[i] == 0) {
            flag = false;
            break;
        }

    // Step 12: Check the value of flag and print "YES" if flag is true, otherwise print "NO"
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

