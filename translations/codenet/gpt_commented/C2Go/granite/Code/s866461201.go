
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    n, fd := 0, [6]int{} // n: number of heights, fd: frequency distribution array
    height := 0.0 // height: variable to store individual height input
    reader := bufio.NewReader(os.Stdin) // reader: input reader

    // Read the number of heights to be processed
    fmt.Fscanf(reader, "%d\n", &n)
    
    // Process each height input
    for n > 0 {
        // Read the height from input
        fmt.Fscanf(reader, "%f\n", &height)
        
        // Increment the appropriate frequency distribution index based on height ranges
        if height >= 185.0 {
            fd[5]++ // Count for height >= 185.0
        } else if height >= 180.0 {
            fd[4]++ // Count for height >= 180.0 and < 185.0
        } else if height >= 175.0 {
            fd[3]++ // Count for height >= 175.0 and < 180.0
        } else if height >= 170.0 {
            fd[2]++ // Count for height >= 170.0 and < 175.0
        } else if height >= 165.0 {
            fd[1]++ // Count for height >= 165.0 and < 170.0
        } else {
            fd[0]++ // Count for height < 165.0
        }
        
        n-- // Decrement the number of heights to be processed
    }

    // Output the frequency distribution as a histogram
    for i := 0; i < 6; i++ {
        fmt.Printf("%d:", i+1) // Print the category number (1 to 6)
        
        // Print asterisks corresponding to the frequency count for each category
        for j := 0; j < fd[i]; j++ {
            fmt.Print("*")
        }
        
        fmt.Println() // Move to the next line after printing the asterisks
    }
}

