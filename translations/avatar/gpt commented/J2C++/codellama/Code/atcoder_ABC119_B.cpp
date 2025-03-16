#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

// Function to solve the currency conversion problem
double solve(vector<double> x, vector<string> u) { 
    // Convert each amount to a standard currency and sum them up
    double total = 0; 
    for (int i = 0; i < x.size(); ++i) { 
        if (u[i] == "JPY") { 
            total += x[i]; // Convert JPY to standard currency (1)
        } else { 
            total += x[i] * 380000; // Convert other currencies to JPY (380000)
        } 
    } 
    return total; // Return the total sum
} 

// Main function to read input and print output
int main() { 
    // Read the number of currency entries
    int N; 
    cin >> N; 
    
    // Initialize vectors to hold the amounts and their corresponding currency units
    vector<double> x(N); 
    vector<string> u(N); 
    
    // Loop to read each amount and its currency unit
    for (int i = 0; i < N; ++i) { 
        cin >> x[i]; // Read the amount
        cin >> u[i]; // Read the currency unit
    } 
    
    // Calculate the total value in a standard currency and print the result
    cout << solve(x, u) << endl; 
    
    return 0; 
} 

