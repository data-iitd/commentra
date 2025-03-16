<<<<<<< HEAD

import "fmt"

func main() {
    var x1, x2, y1, y2 int64
    fmt.Scan(&x1, &y1, &x2, &y2)

    dx := x2 - x1
    dy := y2 - y1

=======
package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read four long long integers from the standard input
    x1, _ := strconv.ParseInt(strings.TrimSpace(string(os.Stdin.Read(1024))), 10, 64)
    y1, _ := strconv.ParseInt(strings.TrimSpace(string(os.Stdin.Read(1024))), 10, 64)
    x2, _ := strconv.ParseInt(strings.TrimSpace(string(os.Stdin.Read(1024))), 10, 64)
    y2, _ := strconv.ParseInt(strings.TrimSpace(string(os.Stdin.Read(1024))), 10, 64)

    // Calculate the differences between the coordinates
    dx := x2 - x1
    dy := y2 - y1

    // Compute the new coordinates based on the differences
>>>>>>> 98c87cb78a (data updated)
    x3 := x2 - dy
    y3 := y2 + dx
    x4 := x1 - dy
    y4 := y1 + dx

<<<<<<< HEAD
    fmt.Println(x3, y3, x4, y4)
=======
    // Output the new coordinates
    fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
>>>>>>> 98c87cb78a (data updated)
}

