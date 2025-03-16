

package main

import "fmt"

func main() {
	var n, sum int
	
	// Step 4: Read input from the user
	fmt.Scan(&n)
	
	// Step 5: Calculate the sum of the first n natural numbers
	sum = (n * (n + 1)) / 2
	
	// Step 6: Print the result
	fmt.Println(sum)
	
	// Step 7: Return from the main function
}

// 