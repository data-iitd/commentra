#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    cin.sync_with_stdio(0); 
    cin.tie(0); 
    cin.exceptions(ios::eofbit); 
    int N; 
    cin >> N; 
    int x[N], y[N]; 
    for (int i = 0; i < N; ++i) { 
        cin >> x[i] >> y[i]; 
    } 
    for (int i = 0; i < N; ++i) { 
        // Create a list to store the angles (thetas) for the current point
        list<double> thetas; 
        
        // Calculate the angle between the current point and all other points
        for (int j = 0; j < N; ++j) { 
            // Skip the current point itself
            if (i == j) continue; 
            
            // Calculate the angle using atan2 and add it to the list
            thetas.push_back(atan2(y[j] - y[i], x[j] - x[i])); 
        } 
        
        // Sort the angles in ascending order
        thetas.sort(); 
        
        // Add the angle that wraps around (2 * PI) to handle circularity
        thetas.push_back(thetas.front() + 2 * M_PI); 
        
        // Initialize a variable to find the maximum angle difference
        double ans = 0; 
        
        // Calculate the maximum angle difference between consecutive angles
        for (int k = 0; k < N - 1; ++k) 
            ans = max(ans, thetas.at(k + 1) - thetas.at(k) - M_PI); 
        
        // Output the result as a fraction of the full circle (2 * PI)
        cout << ans / (M_PI * 2) << "\n"; 
    } 
    return 0; 
}

