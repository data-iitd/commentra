package main

import "fmt"

func main() {
    // Read the number of elements N and the maximum distance X
    var N, X int
    fmt.Scan(&N, &X)
    
    // Read the lengths of the segments into a vector L
    L := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scan(&L[i])
    }
    
    // Initialize the index i and the distance d
    i := 0
    d := 0
    
    // Loop through the segments to calculate the total distance
    for i < N {
        // Add the current segment length to the total distance
        d = d + L[i]
        
        // If the total distance exceeds X, break the loop
        if d > X {
            break
        }
        i++
    }

    // Output the number of segments used
    fmt.Println(i+1)
}

