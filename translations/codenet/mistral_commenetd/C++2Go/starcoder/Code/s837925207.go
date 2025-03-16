
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Initialize arrays h and w of size 6
var h = make([]int, 6)
var w = make([]int, 6)

func main() {
	var x, ans int // Initialize x and ans to zero

	// Read input value of x from the user
	fmt.Scanf("%d", &x)

	// Calculate the answer using the given formula
	ans = x + x*x + x*x*x

	// Output the answer to the user
	fmt.Println(ans)
}

