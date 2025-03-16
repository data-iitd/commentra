
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
    // Define variables to store input coordinates
    var x1, x2, y1, y2 int

    // Read input coordinates from standard input
    fmt.Scanf("%d %d %d %d", &x1, &y1, &x2, &y2)

    // Calculate differences between final and initial coordinates
    dx := x2 - x1
    dy := y2 - y1

    // Calculate coordinates of points to the left and above, and right and below the final point
    x3 := x2 - dy
    y3 := y2 + dx
    x4 := x1 - dy
    y4 := y1 + dx

    // Print the calculated coordinates to the standard output
    fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
}

