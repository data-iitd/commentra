<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var x, kotae int
    fmt.Print("Enter an integer value for x: ")
    fmt.Scanf("%d", &x)
    kotae = x * x * x
    fmt.Printf("The cube of %d is %d.\n", x, kotae)
}

