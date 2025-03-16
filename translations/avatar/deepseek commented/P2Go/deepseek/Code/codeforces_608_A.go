package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of events (n) and the starting time (s)
	var n, s int
	fmt.Fscan(reader, &n, &s)
	
	// Initialize the maximum additional time to 0
	c := 0
	
	// Loop through each event
	for i := 0; i < n; i++ {
		// Read the finish time (f) and the time taken (t) for the current event
		var f, t int
		fmt.Fscan(reader, &f, &t)
		
		// Calculate the additional time required if the event starts at time s
		x := t - (s - f)
		
		// Update the maximum additional time if the current event requires more time
		if x > c {
			c = x
		}
	}
	
	// Print the total time including the maximum additional time
	fmt.Println(s + c)
}

