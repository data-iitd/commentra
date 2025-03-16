
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables for the number of elements and a slice for dynamic array allocation
    var n int
    var data []int

    // Read the number of elements from user input
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d\n", &n)

    // Allocate memory for 'n' integers
    data = make([]int, n)

    // Read 'n' integers from user input into the allocated slice
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &data[i])
    }

    // Initialize variables to find the maximum value and its index
    max := 0
    index := 0

    // Find the maximum value in the slice and its index
    for i := 0; i < n; i++ {
        if data[i] > max {
            max = data[i]
            index = i
        }
    }

    // Initialize a variable to calculate the sum of all elements except the maximum
    a := 0

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

