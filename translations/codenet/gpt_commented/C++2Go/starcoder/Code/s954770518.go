package main

import (
    "fmt"
    "sort"
)

func main() {
    // Declare an array to hold 10 integers
    s := make([]int, 10)

    // Input 10 integers from the user
    for i := 0; i < 10; i++ {
        fmt.Scanf("%d", &s[i])
    }

    // Sort the array of integers in ascending order
    sort.Ints(s)

    // Print the three largest integers from the sorted array
    for i := 9; i > 6; i-- {
        fmt.Println(s[i])
    }
}

