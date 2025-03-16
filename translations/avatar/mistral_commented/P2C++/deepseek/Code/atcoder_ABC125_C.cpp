#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b);
}

// Function to perform Ruiseki algorithm on a given array
vector<int> ruiseki_lr(const vector<int>& array) {
    // Define a helper function to find the GCD of two numbers
    auto op = [](int a, int b) { return gcd(a, b); };
    // Initialize empty vector 'left' and 'right' of size 'n+1'
    int e = 0;
    int n = array.size();
    vector<int> left(n + 1, e);
    vector<int> right(n + 1, e);
    // Iterate through the array and calculate the left and right arrays
    for (int i = 0; i < n; ++i) {
        left[i + 1] = op(left[i], array[i]);
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for (int i = n - 1; i >= 0; --i) {
        right[i] = op(right[i + 1], array[i]);
    }
    // Return the calculated left and right arrays
    return right;
}

int main() {
    // Read input from the user: number of elements in the array and the array itself
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Perform Ruiseki algorithm on the given array and get the left and right arrays
    vector<int> right = ruiseki_lr(a);
    // Initialize answer variable with 0
    int ans = 0;
    // Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
    for (int i = 0; i < n; ++i) {
        ans = max(gcd(a[i], right[i + 1]), ans);
    }
    // Print the final answer
    cout << ans << endl;
    return 0;
}
