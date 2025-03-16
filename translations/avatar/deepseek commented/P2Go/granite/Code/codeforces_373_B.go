

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func sum(k int) int {
    // Initialize the return value and other variables
    ret := 0
    pw := 10
    len := 1
    // Loop to calculate the sum of digits from 1 to k
    for {
        // Calculate the current range of numbers
        cur := min(pw-1, k)
        prev := pw / 10
        // Add the count of numbers in the current range to the result
        ret += (cur - prev + 1) * len
        // Break the loop if the current range exceeds k
        if pw-1 >= k {
            break
        }
        // Update the length and power of ten for the next range
        len++
        pw *= 10
    }
    return ret
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func main() {
    // Read input values for w, m, and k
    scanner := bufio.NewScanner(os.Stdin)
    var w, m, k int
    fmt.Fscanf(scanner, "%d %d %d\n", &w, &m, &k)

    // Initialize the binary search range
    lo := 0
    hi := int(1e18)

    // Perform binary search to find the maximum md
    for hi-lo > 1 {
        md := (lo + hi) / 2
        // Calculate the count of numbers in the range [m, m+md-1]
        c := sum(m+md-1) - sum(m-1)
        // Adjust the search range based on the condition
        if c*k <= w {
            lo = md
        } else {
            hi = md
        }
    }

    // Print the result of the binary search
    fmt.Println(lo)
}

