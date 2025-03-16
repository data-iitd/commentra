
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
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    // Read the size of the array
    N, _ := strconv.Atoi(reader.ReadLine()[2:])

    // Read the elements of the array
    A := make([]int, N)
    for n := 0; n < N; n++ {
        A[n], _ = strconv.Atoi(reader.ReadLine())
    }

    // Sort the array
    sort.Ints(A)

    // Find the minimum and maximum values in the array
    min := A[0]
    max := A[N-1]

    // Count the occurrences of the minimum and maximum values
    mins := int64(0)
    maxs := int64(0)
    for _, value := range A {
        if value == min {
            mins++
        }
        if value == max {
            maxs++
        }
    }

    // Special case: if min == max
    if min == max {
        fmt.Fprintf(writer, "%d %d\n", max-min, mins*(mins-1)/2)
    } else {
        // General case: if min!= max
        fmt.Fprintf(writer, "%d %d\n", max-min, mins*maxs)
    }

    // Close the writer to flush the output
    writer.Flush()
}

// Debugging function to print debug statements
func debug(args...interface{}) {
    fmt.Fprintln(os.Stderr, args...)
}

// End of code