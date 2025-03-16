

#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    int n; 
    cin >> n; // Read the size of the array
    int arr[n]; 
    cin >> arr[0]; // Initialize the first element of the array

    // Read the rest of the elements and calculate the prefix sum
    for (int i = 1; i < n; i++) { 
        int x; 
        cin >> x; 
        arr[i] = x + arr[i - 1]; 
    } 

    int m; 
    cin >> m; // Read the number of queries
    int q[m]; 

    // Read the queries
    for (int i = 0; i < m; i++) { 
        cin >> q[i]; 
    } 

    // Perform binary search for each query and print the result adjusted by +1
    for (int k = 0; k < m; k++) { 
        cout << fun(arr, q[k], n, m) + 1 << endl; 
    } 

    return 0; 
} 

// Binary search function to find the position of q in arr
int fun(int arr[], int q, int n, int m) { 
    int res = 0; 
    int i = 0, j = n; 
    while (i <= j) { 
        int md = i + (j - i) / 2; 
        if (arr[md] == q) return md; 
        else if (arr[md] > q) { 
            res = md; 
            j = md - 1; 
        } else { 
            i = md + 1; 
        } 
    } 
    return res; 
} 

