#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        
        // Create a sorted copy of the input array
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        
        // Calculate the total number of pairs possible in the array
        long long total = (long long)n * (n + 1) / 2;
        
        // Initialize pointers for binary search
        int l = 0, r = n - 1;
        
        // Perform binary search to find the median-like value
        while (l < r) {
            // Calculate the midpoint of the current search range
            int mid = l + (r - l) / 2;
            
            // Get the target value from the sorted array
            int target = sorted[mid];
            
            // Initialize counters for the current state
            int cur = 0;
            long long cnt = 0;
            
            // Create a Binary Indexed Tree (BIT) for counting
            vector<long long> bit(2 * n + 2, 0);
            
            // Initialize the BIT with base values
            for (int x = n + 1; x < bit.size(); x += x & -x)
                bit[x]++;
            
            // Count the number of elements less than or equal to the target
            for (int i = 0; i < n; i++) {
                cur += arr[i] <= target ? 1 : -1;
                
                // Update the BIT with the current count
                for (int x = cur + n + 1; x < bit.size(); x += x & -x)
                    bit[x]++;
                
                // Count the number of valid pairs using the BIT
                for (int x = cur + n; x > 0; x -= x & -x)
                    cnt += bit[x];
            }
            
            // Adjust the search range based on the count of pairs
            if (cnt >= total / 2 + 1)
                r = mid; // Move left if count is sufficient
            else
                l = mid + 1; // Move right if count is insufficient
        }
        
        // Return the median-like value found
        return sorted[l];
    }
};

int main() {
    // Create a vector to hold the input integers
    int N;
    cin >> N;
    vector<int> arr(N);
    
    // Populate the vector with input integers
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    // Create an instance of the Task class to perform the calculation
    Task tsk;
    
    // Solve the task and print the result
    cout << tsk.solve(arr) << endl;
    
    return 0;
}

// <END-OF-CODE>
