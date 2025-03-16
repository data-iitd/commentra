<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    fmt.Println("Enter a string: ")
    fmt.Scanf("%s", &str)

    len := len(str)

    fmt.Println("Reversed string: ")

    for i := len - 1; i >= 0; i-- {
        fmt.Printf("%c", str[i])
    }

    fmt.Println()
}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
