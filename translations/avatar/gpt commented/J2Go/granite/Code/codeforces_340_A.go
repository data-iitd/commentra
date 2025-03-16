
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the user
	s := bufio.NewScanner(os.Stdin)
	
	// Read four integer inputs from the user
	var x, y, a, b int
	s.Scan()
	x, _ = strconv.Atoi(s.Text())
	s.Scan()
	y, _ = strconv.Atoi(s.Text())
	s.Scan()
	a, _ = strconv.Atoi(s.Text())
	s.Scan()
	b, _ = strconv.Atoi(s.Text())
	
	// Initialize variables for calculations
	j := 2
	i := 0
	x1 := 0
	y1 := 0
	c := 0
	ans := true // Flag to check if a valid solution exists
	
	// Determine the maximum of x and y
	c = int(math.Max(float64(x), float64(y)))
	
	// Check if the maximum value exceeds the upper bound b
	if c > b {
		fmt.Println("0") // Output 0 if no valid multiples exist
		ans = false // Set answer flag to false
	}
	
	// Loop to find the least common multiple (LCM) of x and y
	for c%int(math.Min(float64(x), float64(y)))!= 0 && ans {
		// Multiply by j to find the next multiple
		if x > y {
			c = x * j // Calculate next multiple of x
			j++
		} else {
			c = y * j // Calculate next multiple of y
			j++
		}
		
		// Check if the calculated multiple exceeds the upper bound b
		if c > b {
			fmt.Println("0") // Output 0 if no valid multiples exist
			ans = false // Set answer flag to false
			break // Exit the loop
		}
	}
	
	// If a valid multiple was found within the bounds
	if ans {
		count := 0 // Initialize count of valid multiples
		// Find the first multiple of c within the range [a, b]
		for i = a; i <= b; i++ {
			if i%c == 0 {
				break // Break when a multiple is found
			}
		}
		
		// Check if a valid multiple was found within the range
		if i!= b+1 {
			// Calculate the number of multiples of c in the range [a, b]
			fmt.Println(((b - i) / c) + 1)
		} else {
			fmt.Println("0") // Output 0 if no multiples found
		}
	}
}

