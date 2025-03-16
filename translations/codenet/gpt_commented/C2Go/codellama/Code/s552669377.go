package main

import "fmt"

func main() {
    // Declare variables
    var i, n, tmp int // i for loop iteration, n for number of inputs, tmp for temporary input storage
    var min, max, sum int = 1000000, -1000000, 0 // Initialize min, max, and sum

    // Read the number of integers to be processed
    fmt.Scan(&n)
    
    // Loop to read n integers
    for i = 0; i < n; i++ {
        // Read the next integer
        fmt.Scan(&tmp)
        
        // Update min if the current number is smaller
        if min > tmp {
            min = tmp
        }
        
        // Update max if the current number is larger
        if max < tmp {
            max = tmp
        }
        
        // Add the current number to the sum
        sum += tmp
    }

    // Print the minimum, maximum, and sum of the numbers
    fmt.Println(min, max, sum)
}

