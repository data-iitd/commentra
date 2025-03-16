
package main

import "fmt"

func main() {
    var stdin string
    fmt.Scan(&stdin)
    s := stdin
    if "A" in s && "B" in s {
        result := "Yes"
    } else {
        result := "No"
    }
    fmt.Println(result)
}

