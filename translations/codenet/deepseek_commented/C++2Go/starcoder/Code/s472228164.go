<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

// Function to check if a certain condition is met based on the values of x and y
func check(x, y int) string {
    // Check if y is even
    if y%2 == 0 {
        // Calculate t as half of y minus x
<<<<<<< HEAD
        t := int(math.Floor(float64(y)/2.0)) - x
=======
        t := int(math.Floor(float64(0.5*y)) - float64(x))
>>>>>>> 98c87cb78a (data updated)
        // Check if t is non-negative and x minus t is also non-negative
        if t >= 0 && (x-t) >= 0 {
            return "Yes"
        }
    }
    // If the conditions are not met, return "No"
    return "No"
}

func main() {
    var x, y int
    // Read two integers x and y from the standard input
<<<<<<< HEAD
    fmt.Scanf("%d %d\n", &x, &y)
=======
    fmt.Scanf("%d %d", &x, &y)
>>>>>>> 98c87cb78a (data updated)

    // Call the check function with x and y, and print the result
    fmt.Println(check(x, y))
}

