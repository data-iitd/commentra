<<<<<<< HEAD

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

func main() {
    // Declare an unsigned long integer to store the input number
    var n uint64
<<<<<<< HEAD

    // Read the value of n from the standard input
    fmt.Scanf("%d", &n)

    // Initialize a boolean variable to false
    var flg bool = false

    // Check if n is less than 4. If so, print "No" and exit.
    if n < 4 {
        fmt.Println("No")
        os.Exit(0)
    }

    // Check all possible combinations of 4s and 7s that sum up to n
    for i := 0; i <= int(n/4); i++ {
        for j := 0; j <= int(n/7); j++ {
            if i*4+j*7 == n {
=======
    
    // Read the value of n from the standard input
    fmt.Scanf("%d", &n)
    
    // Initialize a boolean variable to false
    var flg bool = false
    
    // Check if n is less than 4. If so, print "No" and exit.
    if n < 4 {
        fmt.Println("No")
        return
    }
    
    // Check all possible combinations of 4s and 7s that sum up to n
    for i := 0; i <= (n / 4); i++ {
        for j := 0; j <= (n / 7); j++ {
            if (i * 4 + j * 7) == n {
>>>>>>> 98c87cb78a (data updated)
                flg = true
                break
            }
        }
        if flg {
            break
        }
    }
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    // Check the value of flg and print "Yes" or "No" accordingly
    if flg {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

