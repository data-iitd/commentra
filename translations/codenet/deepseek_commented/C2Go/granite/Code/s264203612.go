
package main

import "fmt"

func main() {
    // Step 2: Declare variables to store the radius, area, and circumference of the circle.
    var r float64
    var s, l float64
    
    // Step 4: Initialize the value of π (pi) to a constant.
    const p = 3.141592653589
    
    // Step 5: Read the radius from the user.
    fmt.Scanf("%f", &r)
    
    // Step 6: Calculate the area of the circle using the formula: area = π * radius^2.
    s = r * r * p
    
    // Step 7: Calculate the circumference of the circle using the formula: circumference = 2 * π * radius.
    l = 2 * p * r
    
    // Step 8: Print the area and circumference of the circle.
    fmt.Printf("%f %f\n", s, l)
    
    // Step 9: Return 0 to indicate successful execution of the program.
}

// 