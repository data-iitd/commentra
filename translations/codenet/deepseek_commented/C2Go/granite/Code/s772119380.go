
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables
    var n, i, j, d int
    var a []int

    // Read the number of elements in the array
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d\n", &n)

    // Read the elements of the array
    a = make([]int, n)
    for i = 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &a[i])
    }

    // Bubble sort algorithm to sort the array in ascending order
    for i = 0; i < n; i++ {
        for j = n - 1; j >= i + 1; j-- {
            if a[j] < a[j-1] {
                // Swap the elements if they are in the wrong order
                a[j], a[j-1] = a[j-1], a[j]
                // Increment the swap counter
                d++
            }
        }
    }

    // Print the sorted array
    fmt.Printf("%d", a[0])
    for i = 1; i < n; i++ {
        fmt.Printf(" %d", a[i])
    }
    fmt.Println()

    // Print the number of swaps made during the sorting process
    fmt.Println(d)
}

