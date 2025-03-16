
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    // Read the value of N
    N, _ := strconv.ParseInt(os.Args[1], 10, 64)

    // Initialize min to 0 and find the minimum of the first five inputs
    min := int64(0)
    for i := 0; i < 5; i++ {
        if i == 0 {
            min, _ = strconv.ParseInt(os.Args[i+1], 10, 64)
        } else {
            num, _ := strconv.ParseInt(os.Args[i+1], 10, 64)
            if num < min {
                min = num
            }
        }
    }

    // Calculate the result and print it
    fmt.Println(int64(math.Ceil(float64(N)/float64(min))) + 4)
}

