#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    cin >> n; 
    
    // Read n Long integers from the user and store them in the array
    for (int i = 0; i < n; i++) { 
        cin >> ans[i]; 
    } 
    
    // Sort the array in ascending order
    sort(ans, ans + n); 
    
    // Initialize count with the largest element in the sorted array
    count = ans[n - 1]; 
    
    // Iterate through the array from the second largest element to the first
    for (int i = n - 2; i >= 0; i--) { 
        // If the current element is less than the next element, add it to count
        if (ans[i] < ans[i + 1]) { 
            count += ans[i]; 
        } else { 
            // If the current element is not less, decrement it until it is less than the next element
            while (ans[i] >= ans[i + 1]) { 
                ans[i]--; 
            } 
            // If the decremented value is still positive, add it to count
            if (ans[i] > 0) { 
                count += ans[i]; 
            } 
        } 
    } 
    
    // Print the final count
    cout << count << endl; 
}

