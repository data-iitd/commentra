
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)  // Creating a bufio.Reader object for input
    writer := bufio.NewWriter(os.Stdout)  // Creating a bufio.Writer object for output

    input_string, _ := reader.ReadString('\n')  // Reading input and storing it in a string
    input_array := strings.Split(input_string, " ")  // Splitting the input string into an array of strings
    result := 0  // Initializing a variable to store the count of non-zero elements

    // Iterating through the array and updating the result
    for _, str := range input_array {
        result += 1  // Incrementing the result for each element
        if str == "0" {
            break  // Breaking the loop if a zero is encountered
        }
    }

    fmt.Fprintln(writer, result)  // Printing the result to the console
    writer.Flush()  // Flushing the bufio.Writer object
}

