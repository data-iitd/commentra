

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin) // Creating a bufio.Reader to read from the standard input
    A, B, K := readLine(reader) // Calling the readLine() function to read the first line of input and split it into variables A, B, and K
    x, y := solve(A, B, K) // Calling the solve() function to perform the calculations and store the results in variables x and y
    fmt.Println(x, y) // Printing the values of x and y separated by a space character
}

func readLine(reader *bufio.Reader) (int64, int64, int64) { // Function to read a line of input and split it into variables A, B, and K
    line, _ := reader.ReadString('\n') // Reading a line of input and discarding the error
    tokens := strings.Split(strings.TrimSpace(line), " ") // Splitting the line into tokens using the space character as a delimiter and trimming any leading or trailing whitespace
    A, _ := strconv.ParseInt(tokens[0], 10, 64) // Parsing the first token into an int64 value and assigning it to variable A
    B, _ := strconv.ParseInt(tokens[1], 10, 64) // Parsing the second token into an int64 value and assigning it to variable B
    K, _ := strconv.ParseInt(tokens[2], 10, 64) // Parsing the third token into an int64 value and assigning it to variable K
    return A, B, K
}

func solve(A int64, B int64, K int64) (int64, int64) { // Function to perform the calculations and return the results in variables x and y
    x := A
    y := B
    x = A - K // Subtracting K from A and assigning the result to x
    if x < 0 { // Checking if x is negative
        y = B + x // If x is negative, adding the absolute value of x to B and assigning the result to y
        x = 0 // Setting x to zero
    }
    if y < 0 { // Checking if y is negative
        y = 0 // If y is negative, setting it to zero
    }
    return x, y
}

Translate the above Go code to C++ and end with comment "