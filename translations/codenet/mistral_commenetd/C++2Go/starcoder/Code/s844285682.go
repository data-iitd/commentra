
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a int

    fmt.Println("Enter the number of seconds: ")
    fmt.Scanf("%d", &a)

    hours := a / (60 * 60)
    minutes := (a % (60 * 60)) / 60
    seconds := (a % (60 * 60)) % 60

    fmt.Println(hours, ":", minutes, ":", seconds)
}

