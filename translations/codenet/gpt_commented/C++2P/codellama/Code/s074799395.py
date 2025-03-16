#include<iostream> // Include the input-output stream library
using namespace std;

int main() {
    char B, OUT; // Declare two character variables B (input) and OUT (output)
    
    // Read a character input from the user
    cin >> B;
    
    // Determine the output character based on the input character
    if (B == 'A'):
        OUT = 'T'
    elif (B == 'T'):
        OUT = 'A'
    elif (B == 'C'):
        OUT = 'G'
    else:
        OUT = 'C'
    
    // Output the result to the console
    print(OUT)

    return 0; // Indicate that the program ended successfully
}

