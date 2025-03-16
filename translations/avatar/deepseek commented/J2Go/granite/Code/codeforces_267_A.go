
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new Scanner object to read input from the user
	scan := bufio.NewScanner(os.Stdin)
	
	// Read an integer value n from the user and store it in the variable n
	scan.Scan()
	n, _ := strconv.Atoi(scan.Text())
	
	// Loop n times to read pairs of integers and print their greatest common divisor
	for i := 0; i < n; i++ {
		// Read two integers a and b from the user and store them in the variables a and b
		scan.Scan()
		a, _ := strconv.Atoi(scan.Text())
		scan.Scan()
		b, _ := strconv.Atoi(scan.Text())
		
		// Call the sub method with the values of a and b as arguments and print the result
		fmt.Println(sub(a, b))
	}
}

// Define the sub method to calculate the greatest common divisor using the Euclidean algorithm
func sub(a int, b int) int {
	// Initialize min and max to store the smaller and larger of the two input values
	min := int(math.Min(float64(a), float64(b)))
	max := int(math.Max(float64(a), float64(b)))
	
	// Initialize result to 0, which will be used to store the result of the Euclidean algorithm
	result := 0
	
	// Apply the Euclidean algorithm until min becomes 0
	for min > 0 {
		// Add the quotient of max divided by min to result
		result += max / min
		
		// Update max to be the remainder of max divided by min
		max = max % min
		
		// Swap min and max if necessary to ensure min is the smaller value
		curr_min := int(math.Min(float64(min), float64(max)))
		curr_max := int(math.Max(float64(min), float64(max)))
		min = curr_min
		max = curr_max
	}
	
	// Return the value of result, which represents the greatest common divisor
	return result
}

