
package main

import "fmt"

func main() {
    // Declare variables
    var key, i, j, len int
    var a [101]int
    
    // Read the length of the array
    fmt.Scan(&len)
    
    // Read the elements of the array
    for i = 0; i < len; i++ {
        fmt.Scan(&a[i])
    }

    // Perform insertion sort
    for j = 1; j < len; j++ {
        // Print the current state of the array
        for i = 0; i < len; i++ {
            if i!= 0 {
                fmt.Printf(" ")
            }
            fmt.Printf("%d", a[i])
        }
        fmt.Println("") // Move to the next line after printing the array
        
        // Store the current element to be positioned
        key = a[j]
        
        // Shift elements of the sorted segment to the right
        for i = j - 1; i >= 0 && a[i] > key; i-- {
            a[i + 1] = a[i]
        }
        
        // Place the key in its correct position
        a[i + 1] = key
    }

    // Print the sorted array
    for i = 0; i < len; i++ {
        if i!= 0 {
            fmt.Printf(" ")
        }
        fmt.Printf("%d", a[i])
    }
    fmt.Println("") // Move to the next line after printing the sorted array
    
    // End of the program
    return
}

