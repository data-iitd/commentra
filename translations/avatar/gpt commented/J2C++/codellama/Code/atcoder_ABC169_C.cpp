
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in); 
    
    // Read a long integer value from the user
    long a = sc.nextLong(); 
    
    // Read a string value from the user
    string b = sc.next(); 
    
    // Convert the string to a character array for processing
    char[] bChar = b.toCharArray(); 
    
    // Get the length of the character array
    int length = bChar.length; 
    
    // Initialize an empty string to build the integer representation
    string bStr = ""; 
    
    // Loop through each character in the character array
    for (int i = 0; i < length; i++) { 
        // If the character is not a '.', append it to bStr
        if (bChar[i] != '.') { 
            bStr += bChar[i]; 
        } 
    } 
    
    // Convert the built string (bStr) to an integer
    int bInt = Integer.parseInt(bStr); 
    
    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    long result = (a * bInt) / 100; 
    
    // Print the result to the console
    cout << result << endl; 
    
    return 0; 
} 

