
package main

import "fmt"

func main() {
    var B, OUT byte

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
    fmt.Printf("%c\n", OUT)
}

