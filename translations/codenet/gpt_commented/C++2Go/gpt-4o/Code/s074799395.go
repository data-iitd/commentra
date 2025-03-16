package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var B, OUT rune // Declare two rune variables B (input) and OUT (output)

    // Read a character input from the user
    fmt.Scanf("%c", &B)

    // Determine the output character based on the input character
    switch B {
    case 'A':
        OUT = 'T' // If input is 'A', output 'T'
    case 'T':
        OUT = 'A' // If input is 'T', output 'A'
    case 'C':
        OUT = 'G' // If input is 'C', output 'G'
    default:
        OUT = 'C' // For any other input, output 'C'
    }

    // Output the result to the console
    fmt.Println(string(OUT)) // Convert rune to string for output
}

// <END-OF-CODE>
