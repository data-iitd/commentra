
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Initialize a Scanner object to read input from the standard input stream
    in := bufio.NewScanner(os.Stdin)

    // Read the first integer `T` from the input
    in.Scan()
    T, _ := strconv.Atoi(in.Text())

    // Read the second integer `S` from the input
    in.Scan()
    S, _ := strconv.Atoi(in.Text())

    // Read the third integer `q` from the input
    in.Scan()
    q, _ := strconv.Atoi(in.Text())

    // Initialize the variable `previous` with the value of `S`
    previous := S

    // Initialize the variable `answer` with the value of 0
    answer := 0

    // Start a while loop that continues as long as `previous` is less than `T`
    for previous < T {
        // Increment the value of `answer` by 1
        answer++

        // Multiply the value of `previous` by `q`
        previous *= q
    }

    // Print the value of `answer` to the standard output stream
    fmt.Println(answer)
}

