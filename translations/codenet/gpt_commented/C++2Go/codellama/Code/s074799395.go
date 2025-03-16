package main

import "fmt"

func main() {
    var B, OUT byte // Declare two byte variables B (input) and OUT (output)
    
    // Read a byte input from the user
    fmt.Scan(&B)
    
    // Determine the output byte based on the input byte
    if B == 'A' {
        OUT = 'T' // If input is 'A', output 'T'
    } else if B == 'T' {
        OUT = 'A' // If input is 'T', output 'A'
    } else if B == 'C' {
        OUT = 'G' // If input is 'C', output 'G'
    } else {
        OUT = 'C' // For any other input, output 'C'
    }
    
    // Output the result to the console
    fmt.Println(OUT)
}

