<<<<<<< HEAD

import (
    "fmt"
=======
package main

import (
    "fmt"
    "os"
>>>>>>> 98c87cb78a (data updated)
    "strconv"
    "strings"
)

func main() {
    // Step 3: Input a string
    var N string
    fmt.Scanln(&N)

    // Step 4: Calculate the sum of digits
    var S int
    for _, v := range N {
        S += int(v - '0')
    }

    // Step 5: Check if the number is divisible by the sum of its digits
    if int(N[0]-'0')%S == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
<<<<<<< HEAD
=======

    // Step 6: Return 0
    os.Exit(0)
>>>>>>> 98c87cb78a (data updated)
}

