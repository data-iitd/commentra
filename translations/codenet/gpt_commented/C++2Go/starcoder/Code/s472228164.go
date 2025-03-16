package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to check certain conditions based on input values x and y
func check(x, y int) string {
    // Check if y is an even number
    if y%2 == 0 {
        // Calculate t as half of y minus x
        t := (y / 2) - x

        // Check if t is non-negative and if (x - t) is also non-negative
        if t >= 0 && (x-t) >= 0 {
            return "Yes" // Return "Yes" if both conditions are satisfied
        }
    }
    return "No" // Return "No" if y is odd or conditions are not satisfied
}

func main() {
    // Read input values for x and y
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter x and y: ")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSuffix(input, "\n")
    x, _ := strconv.Atoi(strings.Split(input, " ")[0])
    y, _ := strconv.Atoi(strings.Split(input, " ")[1])

    // Call the check function and print the result
    fmt.Println(check(x, y))
}

