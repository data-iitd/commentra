
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables N and D of integer type
	// N and D should be positive integers less than or equal to 20
	var N, D int

	// Initialize variables N and D using os.Stdin.Read function
	fmt.Fscan(os.Stdin, &N, &D)

	// Calculate the quotient of N by (D*2+1) and store it in variable ans
	ans := N / (D*2+1)

	// Calculate the remainder of N by (D*2+1) and store it in variable rem
	rem := N % (D*2+1)

	// Check if the remainder is zero or not
	if rem!= 0 {
		// If the remainder is not zero, increment the value of ans by 1
		ans++
	}

	// Print the value of ans using fmt.Printf function
	fmt.Printf("%d\n", ans)
}

