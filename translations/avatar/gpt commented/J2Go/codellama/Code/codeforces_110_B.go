package main

import "fmt"

func main() {
    // Creating a Scanner object to read input from the console
    var sc = new(Scanner)
    
    // Declaring variables
    var n, i, j, p int = 97 // 'p' is initialized to 97, which is the ASCII value for 'a'
    
    // Reading an integer input from the user which determines the size of the character array
    n = sc.NextInt()
    
    // Creating a character array of size 'n'
    var c []rune = make([]rune, n)
    
    // Filling the character array with letters starting from 'a' (ASCII 97)
    for i = 0; i < 4; i++ { // Looping through the first 4 positions
        for j = i; j < n; j += 4 { // Filling every 4th position starting from 'i'
            c[j] = rune(p) // Assigning the character corresponding to ASCII value 'p'
            p++ // Incrementing 'p' to get the next character
        }
    }
    
    // Printing the filled character array to the console
    for i = 0; i < n; i++ {
        fmt.Print(string(c[i])) // Outputting each character in the array
    }
}

