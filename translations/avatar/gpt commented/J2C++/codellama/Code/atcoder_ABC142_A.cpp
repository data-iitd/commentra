#include <iostream> 
#include <cmath> 
#include <iomanip> 
using namespace std; 

int main() { 
    double input; 
    double countOdd; 
    double result; 

    // Read a line of input and parse it as a double
    cin >> input; 

    // Calculate the count of odd numbers based on the input
    countOdd = round(input / 2); 

    // Create a BigDecimal to hold the result of the division
    result = countOdd / input; 

    // Set the scale of the result to 10 decimal places, rounding half up
    result = setprecision(10) << fixed << result; 

    // Print the result to the console
    cout << result << endl; 

    return 0; 
} 

