
package main

import "fmt"

func main() {
    var a int
    fmt.Print("Enter a number: ")
    fmt.Scan(&a)
    result := a + (a*a) + (a*a*a)
    fmt.Println(result)
}

