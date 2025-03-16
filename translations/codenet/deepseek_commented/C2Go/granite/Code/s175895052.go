
package main

import "fmt"

func main() {
    var n string
    fmt.Scanln(&n)

    // Check if any two consecutive characters in the string n are the same
    if (n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]) {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

