
#include <iostream> 
#include <cmath> 

using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    int n, m, x, min = INT_MAX; 
    cin >> n >> m >> x; 
    
    // Initialize a 2D array to store the input values
    int a[n][m + 1]; 
    
    // Read the values into the 2D array
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= m; j++) 
            cin >> a[i][j]; 
    } 
    
    // Iterate through all possible combinations of rows using bit manipulation
    for (int i = 0; i < pow(2, n); i++) { 
        // Create an array to track which rows are included in the current combination
        int status[n]; 
        
        // Determine which rows are included in the current combination
        for (int j = 0; j < n; j++) { 
            if ((1 & i >> j) == 1) { 
                status[j] = 1; 
            } 
        } 
        
        // Initialize an array to store the sum of the selected rows
        int res[m + 1]; 
        
        // Calculate the sum of the selected rows
        for (int j = 0; j < n; j++) { 
            if (status[j] == 1) { 
                for (int k = 0; k <= m; k++) { 
                    res[k] += a[j][k]; 
                } 
            } 
        } 
        
        // Check if the current combination meets the minimum requirement for each column
        bool flag = true; 
        for (int j = 1; j <= m; j++) { 
            if (res[j] < x) { 
                flag = false; 
                break; 
            } 
        } 
        
        // If the combination is valid, update the minimum value found
        if (flag) 
            min = min(min, res[0]); 
    } 
    
    // Output the result: -1 if no valid combination was found, otherwise the minimum value
    if (min == INT_MAX) 
        cout << -1 << endl; 
    else 
        cout << min << endl; 
    
    return 0; 
} 

