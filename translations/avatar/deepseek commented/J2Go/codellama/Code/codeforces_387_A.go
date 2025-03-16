
package main

import (
    "fmt"
    "time"
)

func main() {
    // Step 1: Read two times from the user, split by colon and convert to LocalTime objects
    var s, t []string
    fmt.Scan(&s, &t)
    x, _ := time.Parse("15:04", s[0]+":"+s[1])
    y, _ := time.Parse("15:04", t[0]+":"+t[1])

    // Step 2: Calculate the difference between the two times
    fmt.Println(x.Sub(y))
}

