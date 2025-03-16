
#include<stdio.h> // Include the standard input/output library

int main(){ // Start of the main function
  char B; // Declare a character variable named B to store the input character
  char OUT; // Declare a character variable named OUT to store the output character

  scanf("%c", &B); // Read a character from the standard input stream and store it in variable B

  // Logic block to determine the output character based on the input character
  if(B == 'A'){ // If the input character is 'A'
    OUT = 'T'; // Set the output character to 'T'
  }
  else if(B == 'T'){ // If the input character is 'T'
    OUT = 'A'; // Set the output character to 'A'
  }
  else if(B == 'C'){ // If the input character is 'C'
    OUT = 'G'; // Set the output character to 'G'
  }
  else{ // If the input character is neither 'A', 'T', nor 'C'
    OUT = 'C'; // Set the output character to the input character itself
  }

  printf("%c\n", OUT); // Output the result character to the standard output stream
}

