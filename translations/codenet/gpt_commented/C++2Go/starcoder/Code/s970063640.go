package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Declare an integer to hold the number of elements
    var n int
    // Read the number of elements from user input
    fmt.Scanf("%d\n", &n)

    // Declare an integer to hold the number of largest elements to sum
    var a int
    // Read the number of largest elements to sum from user input
    fmt.Scanf("%d\n", &a)

    // Initialize a variable to hold the sum of the largest elements
    sum := 0

    // Declare an array to hold the elements
    s := make([]int, n)

    // Read the elements into the array from user input
    for i := 0; i < n; i++ {
        fmt.Scanf("%d\n", &s[i])
    }

    // Sort the array in non-decreasing order
    sort.Ints(s)

    // Sum the largest 'a' elements from the sorted array
    for i := n - 1; i > n - a - 1; i-- {
        sum += s[i]
    }

    // Output the calculated sum of the largest 'a' elements
    fmt.Printf("%d\n", sum)
}

