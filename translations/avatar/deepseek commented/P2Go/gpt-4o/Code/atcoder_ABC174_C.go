package main

import (
	"fmt"
)

func main() {
	var k int
	fmt.Scan(&k) // Read the integer k
	t := 0       // Initialize t to 0

	for i := 1; i <= k; i++ { // Loop from 1 to k
		t = (t % k) * 10 + 7 // Update t based on the current iteration
		if t%k == 0 {        // Check if t is divisible by k
			fmt.Println(i)   // Print the current index if t is divisible by k
			return           // Exit the function as we found the solution
		}
	}
	fmt.Println(-1) // Print -1 indicating no solution was found
}

// <END-OF-CODE>
