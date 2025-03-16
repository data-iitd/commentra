

package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin) // Create a bufio.Reader object to read input from console
    var a string // Declare a string variable to store the input string

    // Read the input string from the console and store it in the 'a' variable
    a, _ = reader.ReadString('\n')

    // Replace all occurrences of ',' in the 'a' string with a single space and store the result in the 'a' variable
    a = strings.Replace(a, ",", " ", -1)

    // Print the modified string stored in the 'a' variable to the console
    fmt.Println(a)
}

