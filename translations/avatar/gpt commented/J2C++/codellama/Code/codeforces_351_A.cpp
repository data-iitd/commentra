#include <iostream> 
#include <cmath> 
#include <string> 
#include <sstream> 
#include <vector> 

using namespace std; 

// Main function definition
int main() { 
    // Initialize variables to store input and output
    int n; 
    double sum_before, sum, max_sum, min_sum, ans; 
    string line; 
    vector<double> arr; 
    
    // Read the number of elements (n)
    cin >> n; 
    
    // Read the input line containing the numbers
    getline(cin, line); 
    
    // Tokenize the input line containing the numbers
    stringstream ss(line); 
    double num; 
    while (ss >> num) 
        arr.push_back(num); 
    
    // Accumulate the total sum of the numbers
    sum_before = 0; 
    for (int i = 0; i < 2 * n; i++) 
        sum_before += arr[i]; 
    
    // Accumulate the sum of the integer parts of the numbers
    sum = 0; 
    for (int i = 0; i < 2 * n; i++) 
        sum += floor(arr[i]); 
    
    // Calculate the maximum possible sum considering non-integer values
    max_sum = min(n, (int)sum_before - sum); 
    
    // Calculate the minimum possible sum considering non-integer values
    min_sum = max(0, sum - (int)sum_before); 
    
    // Determine the answer based on the calculated sums
    if (min_sum > sum_before) 
        ans = min_sum - sum_before; // Case where min_sum is greater than the total sum
    else if (max_sum < sum_before) 
        ans = sum_before - max_sum; // Case where max_sum is less than the total sum
    else { 
        // Case where the total sum is between min_sum and max_sum
        double x = sum_before - floor(sum_before); 
        ans = min(1 - x, x); // Calculate the minimum distance to the nearest integer
    } 
    
    // Print the final answer formatted to three decimal places
    cout << fixed << setprecision(3) << ans << endl; 
    
    return 0; 
} 

