
package main

import "fmt"

func main() {

    var x, kotae int

    fmt.Print("Enter an integer value for x: ")
    fmt.Scan(&x)

    kotae = x*x*x

    fmt.Printf("The cube of %d is %d.\n", x, kotae)

}

