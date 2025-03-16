#include <iostream> 
#include <string> 

using namespace std; 

// Class to perform operations in a modular arithmetic system
class RemRing { 
    long module; // Variable to store the modulus value 

    // Constructor to initialize the modulus
    public: 
        RemRing(long module) { 
            this->module = module; 
        } 

    // Method to perform modular addition
    public: 
        long sum(long a, long b) { 
            return (a + b + module) % module; 
        } 

    // Method to perform modular subtraction
    public: 
        long sub(long a, long b) { 
            return (a - b + module) % module; 
        } 

    // Method to perform modular multiplication
    public: 
        long prod(long a, long b) { 
            return (a * b) % module; 
        } 

    // Method to perform modular division
    public: 
        long div(long a, long b) { 
            return (a * inv(b)) % module; 
        } 

    // Method to compute the modular inverse using the Extended Euclidean Algorithm
    public: 
        long inv(long a) { 
            long b = this->module; 
            long u = 1; 
            long v = 0; 
            
            // Extended Euclidean Algorithm to find the inverse
            while (b > 0) { 
                long t = a / b; 
                a -= t * b; 
                u -= t * v; 
                long z = a; 
                a = b; 
                b = z; 
                z = u; 
                u = v; 
                v = z; 
            } 
            
            // Ensure the result is positive
            u %= this->module; 
            if (u < 0) u += this->module; 
            
            // Return the modular inverse
            return u; 
        } 
};

// Main function to test the above class
int main() { 
    // Declare a string to hold the input
    string s; 
    
    // Read a line of input from the user
    getline(cin, s); 
    
    // Create a RemRing object to perform modular arithmetic
    RemRing r(1000000007); 
    
    // Output the next character in the ASCII sequence of the first character of the input
    cout << (char)(s[0] + 1) << endl; 
    
    return 0; 
} 

// End of code
