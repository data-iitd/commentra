
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read input number as a string
    reader := bufio.NewReader(os.Stdin)
    N, _ := reader.ReadString('\n')

    // Initialize a variable to hold the sum of the digits
    S := 0

    // Calculate the sum of the digits in the input string
    for _, c := range N {
        S += int(c - '0') // Convert character to integer and add to sum
    }

    // Check if the original number is divisible by the sum of its digits
    if num, _ := strconv.Atoi(N); num%S == 0 {
        fmt.Println("Yes") // Output "Yes" if divisible
    } else {
        fmt.Println("No") // Output "No" if not divisible
    }
}

