

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var L []int
    // Initialize an empty slice L to store the results.
    scanner := bufio.NewScanner(os.Stdin)
    // Create a scanner to read input from the standard input.
    scanner.Scan()
    // Read the first input from the user.
    r := 1
    // Initialize the variable r to 1.
    for _, k := range strings.Split(scanner.Text(), " ") {
        // Split the first input into a list of strings and iterate over each string.
        L = append(L, r)
        // Multiply the string '1' by the integer value of the string and append the result to the slice L.
        r++
        // Increment r by 1 for the next iteration.
    }
    scanner.Scan()
    // Read the second input from the user.
    for _, j := range strings.Split(scanner.Text(), " ") {
        // Split the second input into a list of strings and iterate over each string.
        fmt.Println(L[strconv.Atoi(j)-1])
        // For each string, print the element at the index specified by the integer value of the string minus one from the slice L.
    }
}

