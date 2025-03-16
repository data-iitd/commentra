package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an integer variable 'n' for input and an unsigned long long int'm' for storing the result
    n := 0
    m := 0

    // Read an integer value from the user and store it in 'n'
    n, _ = strconv.Atoi(os.Args[1])

    // Initialize'm' with the value of 'n'
    m = n

    // Decrease 'n' by 1 to prepare for the factorial calculation
    n--

    // Loop to calculate the factorial of 'n' (m = n!)
    for ; n > 1; n-- {
        // Multiply'm' by the current value of 'n'
        m *= n
    }

    // Print the calculated factorial value stored in'm'
    fmt.Printf("%d\n", m)
}

