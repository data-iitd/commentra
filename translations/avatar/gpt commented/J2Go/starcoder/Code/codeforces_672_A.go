package main

import "fmt"

// Method to generate a character array from the concatenation of numbers 1 to 1000
func generateString() []rune {
    var sb []rune // Creating a rune slice to efficiently build the string
    
    // Looping through numbers 1 to 1000 and appending them to the rune slice
    for i := 1; i <= 1000; i++ {
        sb = append(sb, rune(i)) // Appending the current number to the rune slice
    }
    
    // Returning the built string
    return sb
}

func main() {
    var n int // Creating an integer variable to store the input
    
    fmt.Scanf("%d", &n) // Reading an integer input from the user
    
    // Printing the character at the (n-1)th index of the generated character array
    fmt.Printf("%c", generateString()[n - 1])
}

