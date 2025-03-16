package main

import "fmt"

func main() {
    // Declare a character array (string) of size 30 to hold user input
    str := make([]byte, 30)

    // Read a line of input from the user and store it in the str array
    fmt.Scanf("%s", &str)

    // Replace the character at index 5 with a space
    str[5] =''

    // Replace the character at index 13 with a space
    str[13] =''

    // Print the modified string to the console
    fmt.Printf("%s\n", str)
}

