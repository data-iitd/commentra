
package main

import "fmt"

func main() {
	var a, b, c, d, e, i int // Declare integer variables to store input values and loop counter
	fmt.Scan(&a, &b, &c) // Read three integer inputs from the user
	
	// Check if the second input (b) is less than or equal to the third input (c)
	if b <= c {
		fmt.Println("NO") // If true, print "NO" and terminate the program
		return
	} else {
		d = a // Initialize variable d with the value of a
		e = d % b // Calculate the remainder of d divided by b
		
		// Loop that runs b times
		for i = 0; i < b; i++ {
			d = d % b // Update the value of d by taking the remainder of d divided by b
			
			// Check if d equals c
			if d == c {
				fmt.Println("YES") // If true, print "YES" and terminate the program
				return
			} else if i!= 0 && d == c { // Check if d equals c and it's not the first iteration
				fmt.Println("NO") // If true, print "NO" and terminate the program
				return
			}
			
			d += a // Increment d by the value of a
		}
	}
	
	fmt.Println("NO") // If the loop completes without finding a solution, print "NO" and terminate the program
}

