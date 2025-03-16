#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Ask the user for the number of elements in the list
    int n;
    cin >> n;

    // Ask the user to input the elements of the list separated by spaces
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    // Initialize a variable to store the answer
    int ans = abs(r[0]);

    // Use a for loop to calculate the sum of the absolute differences between consecutive elements
    for (int i = 1; i < n; i++) {
        ans += abs(r[i] - r[i-1]);
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
