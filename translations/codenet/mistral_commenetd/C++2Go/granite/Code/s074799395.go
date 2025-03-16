

package main // Import the main package for the Go program

import "fmt" // Import the fmt package for input and output operations

func main(){ // Start of the main function
  var B rune // Declare a variable named B of type rune to store the input character
  var OUT rune // Declare a variable named OUT of type rune to store the output character

  fmt.Scanf("%c", &B) // Read a character from the standard input stream and store it in variable B

  // Logic block to determine the output character based on the input character
  switch B { // Use a switch statement to determine the output character based on the input character
  case 'A': // If the input character is 'A'
    OUT = 'T' // Set the output character to 'T'
  case 'T': // If the input character is 'T'
    OUT = 'A' // Set the output character to 'A'
  case 'C': // If the input character is 'C'
    OUT = 'G' // Set the output character to 'G'
  default: // If the input character is neither 'A', 'T', nor 'C'
    OUT = B // Set the output character to the input character itself
  }

  fmt.Printf("%c\n", OUT) // Output the result character to the standard output stream
}



