package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for loop index, input values, and a product variable
    var i, a, b, s int
    // Array to count occurrences of each number (1 to 4)
    count := [4]int{0, 0, 0, 0}

    // Initialize the count array to zero
    for i = 0; i < 4; i++ {
        count[i] = 0
    }

    // Read pairs of integers and update their counts
    for i = 0; i < 3; i++ {
        // Read two integers from input
        a, b = readInput()
        // Increment the count for each integer read
        count[a-1]++
        count[b-1]++
    }

    // Initialize the product variable
    s = 1
    // Calculate the product of counts
    for i = 0; i < 4; i++ {
        s *= count[i]
    }

    // Check if the product equals 4, indicating each number appears at least once
    if s == 4 {
        fmt.Println("YES") // Output YES if all numbers are present
    } else {
        fmt.Println("NO")  // Output NO if any number is missing
    }
}

func readInput() (int, int) {
    // Read two integers from input
    s := strings.Split(os.Args[1], " ")
    a, _ := strconv.Atoi(s[0])
    b, _ := strconv.Atoi(s[1])
    return a, b
}

