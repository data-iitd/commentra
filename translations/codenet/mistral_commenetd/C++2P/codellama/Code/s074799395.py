
#include<iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace for easier access to iostream functions

int main(){ // Start of the main function
  char B; // Declare a character variable named B to store the input character
  char OUT; // Declare a character variable named OUT to store the output character

  cin >> B; // Read a character from the standard input stream and store it in variable B

  # Logic block to determine the output character based on the input character
  if(B == 'A'): # If the input character is 'A'
    OUT = 'T'; # Set the output character to 'T'
  elif(B == 'T'): # If the input character is 'T'
    OUT = 'A'; # Set the output character to 'A'
  elif(B == 'C'): # If the input character is 'C'
    OUT = 'G'; # Set the output character to 'G'
  else: # If the input character is neither 'A', 'T', nor 'C'
    OUT = 'C'; # Set the output character to the input character itself

  cout << OUT << endl; # Output the result character to the standard output stream
}

