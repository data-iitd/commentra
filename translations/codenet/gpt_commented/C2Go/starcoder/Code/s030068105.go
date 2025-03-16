package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for the number of elements and a pointer for dynamic array allocation
    var n int
    var data []int

    // Read the number of elements from user input
    fmt.Scanf("%d\n", &n)

    // Allocate memory for 'n' integers
    data = make([]int, n)

    // Read 'n' integers from user input into the allocated array
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &data[i])
    }

    // Initialize variables to find the maximum value and its index
    var max int = 0
    var index int

    // Find the maximum value in the array and its index
    for i := 0; i < n; i++ {
        if data[i] > max {
            max = data[i]
            index = i
        }
    }

    // Initialize a variable to calculate the sum of all elements except the maximum
    var a int = 0

    // Calculate the sum of all elements excluding the maximum value
    for i := 0; i < n; i++ {
        if i!= index {
            a += data[i]
        }
    }

    // Compare the sum of the other elements with the maximum value and print the result
    if a > max {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

