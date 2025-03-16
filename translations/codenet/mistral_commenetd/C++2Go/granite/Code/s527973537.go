

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare and initialize variables
    reader := bufio.NewReader(os.Stdin)
    N := "" // string to store the input number
    S := 0 // sum of digits of the number

    // Read the input number from the standard input
    fmt.Print("Enter a number: ")
    N, _ = reader.ReadString('\n')
    N = strings.TrimSpace(N)

    // Calculate the sum of digits of the number
    for _, r := range N {
        // Increment the sum by the actual digit value
        S += int(r - '0')
    }

    // Check if the number is divisible by the sum of its digits
    if num, _ := strconv.Atoi(N); num%S == 0 {
        fmt.Println("Yes") // Output "Yes" if the number is divisible
    } else {
        fmt.Println("No") // Output "No" otherwise
    }
}

