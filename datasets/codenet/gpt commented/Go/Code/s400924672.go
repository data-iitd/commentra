package main

import "fmt"

func main() {
    // Declare variables for radius (r), distance (D), and initial value (x)
	var r, D, x int
    
    // Read input values for r, D, and x from the user
	fmt.Scan(&r, &D, &x)

    // Loop to perform calculations and print results for 10 iterations
	for i := 1; i <= 10; i++ {
        // Calculate and print the result of the formula r*x - D
		fmt.Println(r*x - D)
        
        // Update x for the next iteration using the formula r*x - D
		x = r*x - D
	}
}
