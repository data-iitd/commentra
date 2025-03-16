package main

import (
    "bufio"  // Importing bufio for input operations
    "fmt"    // Importing fmt for output operations
    "os"     // Importing os for standard input and output
    "strings" // Importing strings for string manipulation
)

func main() {
    reader := bufio.NewReader(os.Stdin)  // Creating a bufio.Reader object for input
    input, _ := reader.ReadString('\n')   // Reading input until a newline
    inputArray := strings.Fields(input)    // Splitting the input into an array of strings

    result := 0  // Initializing a variable to store the count of non-zero elements

    // Iterating through the array and updating the result
    for _, str := range inputArray {
        result++  // Incrementing the result for each element
        if str == "0" { // Breaking the loop if a zero is encountered
            break
        }
    }

    fmt.Println(result)  // Printing the result to the console
}

// <END-OF-CODE>
