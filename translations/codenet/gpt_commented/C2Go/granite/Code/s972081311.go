
package main

import "fmt"

func main() {
    // Declare variables to hold the input number and the sum
    var n, sum int

    // Read an integer input from the user
    fmt.Scan(&n)

    // Calculate the sum of the first n natural numbers using the formula n*(n+1)/2
    sum = (n * (n + 1)) / 2

    // Print the calculated sum to the console
    fmt.Println(sum)
}

