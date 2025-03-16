#include <iostream>  // Including the iostream library for input and output operations
#include <sstream>   // Including the sstream library for string stream operations
#include <vector>    // Including the vector library for using dynamic arrays
#include <cmath>     // Including the cmath library for mathematical functions
#include <iomanip>   // Including the iomanip library for output formatting

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // Optimize input/output operations
    cin.tie(nullptr);             // Untie cin from cout for faster input

    int n;
    cin >> n;  // Reading the number of test cases

    vector<double> arr(2 * n);  // Creating a vector to store the array elements
    double sum_before = 0, sum = 0;  // Initializing variables
    int non_int = 0;  // Counter for non-integer values

    // Reading the elements of the array
    for (int i = 0; i < 2 * n; i++) {
        double num;
        cin >> num;  // Reading the current number
        sum_before += num;  // Adding the current number to sum_before
        if (num != floor(num)) non_int++;  // Incrementing non_int if the number is not an integer
        sum += floor(num);  // Adding the floor value of the current number to sum
        arr[i] = num;  // Storing the current number in the array
    }

    // Calculating the maximum and minimum sums
    double max_sum = min(n, non_int) + sum;
    double min_sum = max(0.0, non_int - n) + sum;

    // Calculating the answer based on the given conditions
    double ans;
    if (min_sum > sum_before) ans = (min_sum - sum_before);
    else if (max_sum < sum_before) ans = (sum_before - max_sum);
    else {
        double x = sum_before - floor(sum_before);
        ans = min(1 - x, x);
    }

    // Printing the answer with three decimal places
    cout << fixed << setprecision(3) << ans << endl;

    return 0;  // Indicating that the program ended successfully
}

// <END-OF-CODE>
