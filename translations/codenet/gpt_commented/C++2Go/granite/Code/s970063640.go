
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    // Declare an integer to hold the number of elements
    var n int
    // Read the number of elements from user input
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &n)

    // Declare an integer to hold the number of largest elements to sum
    var a int
    // Read the number of largest elements to sum from user input
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a)

    // Initialize a variable to hold the sum of the largest elements
    var sum int

    // Declare an array to hold the elements
    s := make([]int, n)

    // Read the elements into the array from user input
    for i := 0; i < n; i++ {
        fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &s[i])
    }

    // Sort the array in non-decreasing order
    sort.Ints(s)

    // Sum the largest 'a' elements from the sorted array
    for i := n - 1; i > n - a - 1; i-- {
        sum += s[i]
    }

    // Output the calculated sum of the largest 'a' elements
    fmt.Println(sum)
}

