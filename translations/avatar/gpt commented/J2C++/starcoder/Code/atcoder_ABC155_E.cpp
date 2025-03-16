#include <iostream>
#include <string>
using namespace std;

int main() {
    // Define a constant for a large number (infinity) for potential use in calculations
    const long long INF = (long long) 1e15;
    
    // Read the input number as a string
    string number;
    cin >> number;
    
    // Initialize an array to hold the digits of the number in reverse order
    int digits[number.length() + 1];
    
    // Convert the input string into an array of digits (in reverse order)
    for (int i = 0; i < number.length(); i++) {
        digits[i] = number[number.length() - 1 - i] - '0';
    }
    
    // Initialize a variable to count the total number of bills
    int bills = 0;
    
    // Process each digit to calculate the total number of bills needed
    for (int i = 0; i <= number.length(); i++) {
        // Handle carry over for digits equal to 10
        if (digits[i] == 10) {
            digits[i + 1]++;
            digits[i] = 0;
        }
        
        // If the digit is less than 5, add it directly to the bills
        if (digits[i] < 5) {
            bills += digits[i];
        }
        // If the digit is exactly 5, check the next digit for rounding
        else if (digits[i] == 5) {
            if (digits[i + 1] >= 5) {
                digits[i + 1]++;
            }
            bills += 5;
        }
        // If the digit is greater than 5, round up to the next ten
        else {
            digits[i + 1]++;
            bills += 10 - digits[i];
        }
    }
    
    // Output the total number of bills calculated
    cout << bills << endl;
}

