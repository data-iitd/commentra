
#include <iostream> 
#include <cstdlib> 
#include <cmath> 
#include <algorithm> 
#include <set> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    int n; 
    long k; 
    long arr[n]; 
    set<long> set; 
    int count = 0; 
    
    // Read the number of elements in the array
    cin >> n; 
    
    // Read the value of k
    cin >> k; 
    
    // Read n long integers into the array
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 
    
    // Sort the array to facilitate the processing of elements
    sort(arr, arr + n); 
    
    // Iterate through the sorted array to apply the conditions
    for (int i = 0; i < n; i++) { 
        // Check if the current element is not divisible by k
        if (arr[i] % k != 0) { 
            count++; // Increment count for valid element
            set.insert(arr[i]); // Add the element to the set
        } 
        // Check if the current element is divisible by k and its corresponding k-factor is not in the set
        else if (set.find(arr[i] / k) == set.end()) { 
            count++; // Increment count for valid element
            set.insert(arr[i]); // Add the element to the set
        } 
    } 
    
    // Output the final count of valid elements
    cout << count << endl; 
    
    return 0; 
} 

