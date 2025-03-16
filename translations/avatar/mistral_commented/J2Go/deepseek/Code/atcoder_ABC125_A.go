package main

import (
	"fmt"
)

func main() {
	// Create a new Scanner object to read input from the standard input stream
	var sec, per_num, max_sec int
	fmt.Scan(&sec, &per_num, &max_sec)

	// Convert the last input (max_sec) to a float64 type and add 0.5 to it to get the maximum number of seconds with a fractional part
	max_sec_float := float64(max_sec) + 0.5

	// Initialize a counter variable ans_num to zero
	ans_num := 0

	// Start a for loop that runs from the initial value sec to the final value max_sec_float with a step size of sec. In each iteration of the loop, add per_num to ans_num
	for i := sec; i < int(max_sec_float); i += sec {
		ans_num += per_num
	}

	// Print the result ans_num to the standard output stream
	fmt.Println(ans_num)
}

