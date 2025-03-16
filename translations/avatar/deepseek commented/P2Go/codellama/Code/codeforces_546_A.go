
package main

import "fmt"

func main() {
	var k, n, w string
	fmt.Scan(&k, &n, &w)
	// Taking input for k, n, and w
	if 1 <= len(k) && len(w) <= 1000 {
		// Checking if k and w are within the specified range
		total := 0
		// Initializing total to 0
		for i := 1; i <= len(w); i++ {
			// Looping from 1 to w (inclusive)
			total += (i * len(k))
			// Multiplying the current iteration number by k and adding to total
		}
		if total > len(n) {
			// Checking if total is greater than n
			fmt.Println(total - len(n))
			// Printing the difference between total and n if total is greater
		} else {
			fmt.Println(0)
			// Printing 0 if total is not greater than n
		}
	}
}

