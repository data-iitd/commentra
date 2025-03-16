
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Step 1: Declare necessary variables
    var a [10000]int
    var min, max, n, i int
    var sum int64

    // Step 2: Read the number of elements (n) from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d\n", &n)

    // Step 3: Read the elements of the array from the user and calculate the sum
    for i = 0; i < n; i++ {
        fmt.Fscanf(reader, "%d\n", &a[i])
        sum += int64(a[i])
    }

    // Step 4: Find the minimum and maximum values in the array
    max = min = a[0]
    for i = 1; i < n; i++ {
        if a[i] > max {
            max = a[i]
        }
        if a[i] < min {
            min = a[i]
        }
    }

    // Step 5: Print the minimum, maximum, and sum of the elements
    fmt.Printf("%d %d %d\n", min, max, sum)
}

