package main

import (
	"fmt"
	"math"
	"bufio"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object for user input
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read a long integer N from user input
	scanner.Scan()
	N, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	
	// Initialize a variable to hold the minimum value
	var min int64 = 0
	
	// Loop to read five long integers and find the minimum
	for i := 0; i < 5; i++ {
		// For the first iteration, directly assign the value to min
		if i == 0 {
			scanner.Scan()
			min, _ = strconv.ParseInt(scanner.Text(), 10, 64)
		} else {
			// For subsequent iterations, update min if a smaller value is found
			scanner.Scan()
			current, _ := strconv.ParseInt(scanner.Text(), 10, 64)
			if current < min {
				min = current
			}
		}
	}
	
	// Calculate the result by dividing N by min, rounding up, and adding 4
	result := int64(math.Ceil(float64(N) / float64(min))) + 4
	fmt.Println(result)
}

