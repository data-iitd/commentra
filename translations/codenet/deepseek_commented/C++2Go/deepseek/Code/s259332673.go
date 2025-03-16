package main

import (
	"fmt"
)

func main() {
	// Declare integer variables to store input values
	var h1, h2, m1, m2, k int
	
	// Read input values for h1, m1, h2, m2, and k from the standard input
	fmt.Scan(&h1, &m1, &h2, &m2, &k)
	
	// Calculate the difference in minutes between h2:m2 and h1:m1
	ans := (h2 * 60 + m2) - (h1 * 60 + m1)
	
	// Print the result of subtracting k from the calculated difference
	fmt.Println(ans - k)
}

