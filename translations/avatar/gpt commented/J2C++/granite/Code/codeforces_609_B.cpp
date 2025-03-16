
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements (n) and the maximum value (m)
    int n, m;
    cin >> n >> m;
    
    // Initialize an array to store the input values
    vector<int> arr(n);
    
    // Initialize a frequency array to count occurrences of each number from 1 to 10
    vector<int> gen(11, 0); // gen[0] will remain unused
    
    // Read n integers from input and populate the arr and gen arrays
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Store the input value in arr
        gen[arr[i]]++; // Increment the count of the corresponding number in gen
    }
    
    // Initialize a variable to hold the final answer
    long long ans = 0;
    
    // Calculate the number of valid pairs (i, k) where i!= k
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= m; k++) {
            if (i!= k) {
                // Add the product of the counts of i and k to the answer
                ans += (long long) gen[i] * gen[k];
            }
        }
    }
    
    // Since each pair (i, k) is counted twice, divide the result by 2
    cout << ans / 2 << endl;
    
    return 0;
}
