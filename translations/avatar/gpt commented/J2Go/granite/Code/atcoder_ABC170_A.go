
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a scanner to read input from the standard input stream
    scanner := bufio.NewScanner(os.Stdin)

    // Create a variable to store the result
    result := 0

    // Read a line of input, split it into an array of strings based on spaces
    scanner.Scan()
    input_array := strings.Split(scanner.Text(), " ")

    // Iterate through each string in the input array
    for _, str := range input_array {
        // Convert the string to an integer
        num, _ := strconv.Atoi(str)

        // Increment the result for each non-zero input
        if num!= 0 {
            result += 1
        }

        // If the input is "0", break out of the loop
        if num == 0 {
            break
        }
    }

    // Print the result, which is the count of non-zero inputs before the first "0"
    fmt.Println(result)
}

