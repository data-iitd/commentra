<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n uint64
    var flg bool = false

    // Read the input number
<<<<<<< HEAD
    fmt.Scanln(&n)
=======
    fmt.Scanf("%d\n", &n)
>>>>>>> 98c87cb78a (data updated)

    // Check if n is less than 4
    if n < 4 {
        fmt.Println("No")
        return
    }

    // Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
    for i := 0; i <= int(n/4); i++ { // Outer loop: i from 0 to n/4
        for j := 0; j <= int(n/7); j++ { // Inner loop: j from 0 to n/7
            if i*4+j*7 == n { // Check if the sum of i*4 and j*7 equals n
                flg = true // Set the flag to true if found
                break // Exit both loops
            }
        }
        if flg {
<<<<<<< HEAD
            break
=======
            break // Exit the outer loop if flag is true
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Print the result
    if flg {
<<<<<<< HEAD
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
=======
        fmt.Println("Yes") // Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
    } else {
        fmt.Println("No") // Print "No" otherwise
>>>>>>> 98c87cb78a (data updated)
    }
}

