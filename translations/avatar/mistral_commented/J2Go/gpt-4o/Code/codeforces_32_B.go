package main // Defining the main package

import (
    "bufio" // Importing bufio for buffered I/O
    "fmt"   // Importing fmt for formatted I/O
    "os"    // Importing os for standard I/O
)

func main() { // Starting the main function
    reader := bufio.NewReader(os.Stdin) // Creating a new buffered reader to read input from the console
    input, _ := reader.ReadString('\n')   // Reading a string from the console until a newline character

    n := []rune(input) // Converting the string to a slice of runes (characters)

    s := false // Initializing a boolean variable 's' to false

    for i := 0; i < len(n); i++ { // Starting a for loop to iterate through each character in the slice 'n'
        if n[i] == '.' { // Checking if the current character is a '.'
            if s { // If the boolean variable 's' is true
                fmt.Print(1) // Printing '1' to the console
                s = false // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                fmt.Print(0) // Printing '0' to the console
            }
        } else { // If the current character is not a '.'
            if s { // If the boolean variable 's' is true
                fmt.Print(2) // Printing '2' to the console
                s = false // Setting the boolean variable 's' to false
            } else { // If the boolean variable 's' is false
                s = true // Setting the boolean variable 's' to true
            }
        }
    }
}

// <END-OF-CODE>
