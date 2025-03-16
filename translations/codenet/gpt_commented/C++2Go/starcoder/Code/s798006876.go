package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define a constant for the maximum number of elements
const MAX_N = 1e3

// Array to hold input data
var data [MAX_N]int

func main() {
    var m, nmi, nma int

    // Read inputs m, nmi, and nma until nmi is not equal to 0
    for {
        _, err := fmt.Scanf("%d %d %d", &m, &nmi, &nma)
        if err!= nil || nmi == 0 {
            break
        }

        // Read m elements into the data array
        for i := 0; i < m; i++ {
            _, err := fmt.Scanf("%d", &data[i])
            if err!= nil {
                break
            }
        }

        // Initialize variables to track the maximum difference and the answer index
        var ma, ans int

        // Loop through the specified range from nmi-1 to nma-1
        for i := nmi - 1; i < nma - 1; i++ {
            // Check if the current difference is greater than the maximum found so far
            if ma <= data[i] - data[i+1] {
                ans = i + 1 // Update the answer index
                ma = data[i] - data[i+1] // Update the maximum difference
            }
        }

        // Output the index of the element that produced the maximum difference
        fmt.Println(ans)
    }
}

