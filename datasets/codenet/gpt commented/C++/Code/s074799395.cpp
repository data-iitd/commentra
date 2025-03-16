#include<iostream> // Include the input-output stream library
using namespace std;

int main() {
    char B, OUT; // Declare two character variables B (input) and OUT (output)
    
    // Read a character input from the user
    cin >> B;
    
    // Determine the output character based on the input character
    if (B == 'A') 
        OUT = 'T'; // If input is 'A', output 'T'
    else if (B == 'T') 
        OUT = 'A'; // If input is 'T', output 'A'
    else if (B == 'C') 
        OUT = 'G'; // If input is 'C', output 'G'
    else 
        OUT = 'C'; // For any other input, output 'C'
    
    // Output the result to the console
    cout << OUT << endl;

    return 0; // Indicate that the program ended successfully
}
