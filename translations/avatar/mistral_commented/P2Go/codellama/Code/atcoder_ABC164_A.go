
package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Get the input as a list of two integers, S and W, using the map function
    S, W := map(strconv.Atoi, strings.Split(input(), " "))

    // Check if the condition S <= W is true or false and print the corresponding message
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

// Get the input from the user
func input() string {
    var input string
    fmt.Scanln(&input)
    return input
}

// Map the function Atoi to the input string
func map(f func(string) int, input []string) (int, int) {
    return f(input[0]), f(input[1])
}

// END-OF-CODE
