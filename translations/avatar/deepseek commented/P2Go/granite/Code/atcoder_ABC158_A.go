

package main

import "fmt"

func main() {
    var s string
    fmt.Scanln(&s)  // Take input from the user and store it in the variable s
    result := "Yes"
    if!strings.Contains(s, "A") ||!strings.Contains(s, "B") {
        result = "No"
    }
    fmt.Println(result)  // Print the result
}

