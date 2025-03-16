
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read the number of elements (n) and the threshold (k) from input
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    k, _ := strconv.Atoi(scanner.Text())
    
    // Initialize an array to hold the input values
    bb := make([]int, n)
    
    // Read n integers into the bb array
    for i := 0; i < n; i++ {
        scanner.Scan()
        bb[i], _ = strconv.Atoi(scanner.Text())
    }
    
    // Initialize an array to hold the results and a counter for the results
    aa := make([]int, n)
    m := 0
    
    // Process the input array in reverse order
    for a := n - 1; a >= 0; a-- {
        j := 0
        // While there are still counts left for the current index in bb
        for bb[a] > 0 {
            // Check if the current index in aa is valid
            if aa[j] >= a+k {
                bb[a]-- // Decrease the count for bb[a]
            }
            j++ // Move to the next index in aa
        }
        // Shift elements in aa to make space for the current index
        for j_ := m; j_ > j; j_-- {
            aa[j_] = aa[j_-1]
        }
        aa[j] = a // Place the current index in aa
    }
    
    // Output the results, incrementing by 1 for 1-based indexing
    for i := 0; i < n; i++ {
        fmt.Print(aa[i]+1, " ")
    }
    fmt.Println() // Print a newline at the end
}

