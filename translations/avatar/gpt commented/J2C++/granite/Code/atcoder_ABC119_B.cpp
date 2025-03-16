
#include <iostream> 
#include <string> 
#include <vector> 
#include <numeric> 

using namespace std; 

// Function to solve the currency conversion problem
double solve(const vector<double>& x, const vector<string>& u) { 
    // Convert each amount to a standard currency and sum them up
    return accumulate(x.begin(), x.end(), 0.0, 
        [&u](double sum, double amount) { 
            return sum + (u[&amount - &x[0]] == "JPY"? amount : amount * 380000); 
        }); 
} 

int main() { 
    // Create a Scanner object to read input from the console
    Scanner sc(cin); 
      
      // Read the number of currency entries
    int N = sc.nextInt(); 
      
      // Initialize vectors to hold the amounts and their corresponding currency units
    vector<double> x(N); 
    vector<string> u(N); 
      
      // Loop to read each amount and its currency unit
    for (int i = 0; i < N; ++i) { 
        x[i] = sc.nextDouble(); // Read the amount
        u[i] = sc.next(); // Read the currency unit
    } 
      
      // Calculate the total value in a standard currency and print the result
    cout << solve(x, u) << endl; 
      
      // Close the scanner to prevent resource leaks
    sc.close(); 
} 

