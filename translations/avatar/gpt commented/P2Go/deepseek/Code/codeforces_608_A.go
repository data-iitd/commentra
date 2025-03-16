package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Use bufio for faster input reading
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of intervals (n) and the starting point (s)
	var n, s int
	fmt.Fscan(reader, &n, &s)
	
	// Initialize a variable to keep track of the maximum additional distance (c)
	c := 0
	
	// Iterate over each interval
	for i := 0; i < n; i++ {
		// Read the start (f) and end (t) of the interval
		var f, t int
		fmt.Fscan(reader, &f, &t)
		
		// Calculate the additional distance that can be covered
		x := t - (s - f)
		
		// Update the maximum additional distance if the current one is greater
		if x > c {
			c = x
		}
	}
	
	// Output the total distance covered, which is the starting point plus the maximum additional distance
	fmt.Println(s + c)
}

