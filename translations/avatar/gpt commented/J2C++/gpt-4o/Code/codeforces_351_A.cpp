#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    // Initialize input stream
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of elements (n)
    int n;
    cin >> n;
    
    // Vector to store the numbers
    vector<double> arr(2 * n);
    int non_int = 0; // Counter for non-integer values
    double sum_before = 0, sum = 0; // Variables to store sums
    
    // Loop through the input numbers
    for (int i = 0; i < 2 * n; i++) {
        double num;
        cin >> num; // Read the next number
        
        // Accumulate the total sum of the numbers
        sum_before += num;
        
        // Check if the number is non-integer and update the counter
        if (num != floor(num))
            non_int++;
        
        // Accumulate the sum of the integer parts of the numbers
        sum += floor(num);
        
        // Store the number in the array
        arr[i] = num;
    }
    
    // Calculate the maximum possible sum considering non-integer values
    double max_sum = min(n, non_int) + sum;
    
    // Calculate the minimum possible sum considering non-integer values
    double min_sum = max(0.0, non_int - n) + sum;
    
    double ans; // Variable to store the final answer
    
    // Determine the answer based on the calculated sums
    if (min_sum > sum_before)
        ans = (min_sum - sum_before); // Case where min_sum is greater than the total sum
    else if (max_sum < sum_before)
        ans = (sum_before - max_sum); // Case where max_sum is less than the total sum
    else {
        // Case where the total sum is between min_sum and max_sum
        double x = sum_before - floor(sum_before);
        ans = min(1 - x, x); // Calculate the minimum distance to the nearest integer
    }
    
    // Print the final answer formatted to three decimal places
    cout << fixed << setprecision(3) << ans << endl;
    
    return 0;
}

// <END-OF-CODE>
