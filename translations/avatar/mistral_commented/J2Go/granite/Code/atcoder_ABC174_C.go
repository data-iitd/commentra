

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

var (
    reader = bufio.NewReader(os.Stdin)
    writer = bufio.NewWriter(os.Stdout)
)

func readInt() (int, error) {
    // Function to read an integer from the standard input
    bytes, err := reader.ReadBytes('\n')
    if err!= nil {
        return 0, err
    }
    number, err := strconv.Atoi(strings.TrimSpace(string(bytes)))
    if err!= nil {
        return 0, err
    }
    return number, nil
}

func main() {
    // Main function to call the solve function and print the result
    K, err := readInt() // Reading the input value of K
    if err!= nil {
        panic(err)
    }
    result := solve(K) // Calling the solve function
    fmt.Fprintln(writer, result) // Printing the result
    writer.Flush()
}

func solve(K int) int {
    // Function to find the answer
    // Checking if K is even or multiple of 5, returning -1 if true
    if K%2 == 0 || K%5 == 0 {
        return -1
    }
    // If K is multiple of 7, dividing it by 7 and multiplying it by 9
    if K%7 == 0 {
        K /= 7
    }
    K *= 9
    // Initializing the answer variable and the remainder variable
    ans := 1
    remainder := 10 % K
    // Using a while loop to find the answer
    for remainder!= 1 {
        ans++ // Incrementing the answer variable
        remainder = remainder*10 % K // Updating the remainder variable
    }
    // Returning the answer
    return ans
}

These comments should help make the code more readable and understandable for anyone who reads it.

