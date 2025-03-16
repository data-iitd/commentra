
#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std; 

// Declare a static Scanner object for input
static Scanner scanner; 

int main() { 
    // Initialize the Scanner object to read input from the console
    scanner = new Scanner(System.in); 
    
    // Read an integer N from the user
    int N = gi(); 
    
    // Initialize a long variable i starting from 357
    long i = 357; 
    
    // Initialize a counter to keep track of valid numbers
    int c = 0; 
    
    // Loop until i exceeds N
    while (i <= N) { 
        // Convert the current number i to a String
        string s = to_string(i); 
        
        // Check if the string contains '3', '5', and '7'
        if (s.find("3") != string::npos && s.find("5") != string::npos && s.find("7") != string::npos) 
            c++; // Increment the counter if all digits are present
        
        // Create a StringBuilder to construct a new number
        stringstream sb; 
        bool f = false; // Flag to indicate if a replacement has occurred
        
        // Iterate through the digits of the number in reverse order
        for (int j = 0; j < s.length(); j++) { 
            char a = s[s.length() - 1 - j]; // Get the current digit
            
            // If a replacement has occurred, append the digit as is
            if (f) { 
                sb << a; 
            } else { 
                // Replace '3' with '5' and set the flag
                if (a == '3') { 
                    sb << '5'; 
                    f = true; 
                } 
                // Replace '5' with '7' and set the flag
                else if (a == '5') { 
                    sb << '7'; 
                    f = true; 
                } 
                // If it's neither, append '3'
                else { 
                    sb << '3'; 
                } 
            } 
        } 
        
        // If no replacement occurred, append '3' to the StringBuilder
        if (!f) 
            sb << '3'; 
        
        // Reverse the constructed number and parse it back to long
        string s2 = sb.str(); 
        reverse(s2.begin(), s2.end()); 
        i = stol(s2); 
    } 
    
    // Print the total count of valid numbers found
    cout << c << endl; 
    
    return 0; 
} 

// Method to read a String input from the user
string gs() { 
    return scanner.next(); 
} 

// Method to read an integer input from the user
int gi() { 
    return stoi(scanner.next()); 
} 

// Method to read a long input from the user
long gl() { 
    return stol(scanner.next()); 
} 

// Method to read a double input from the user
double gd() { 
    return stod(scanner.next()); 
} 

