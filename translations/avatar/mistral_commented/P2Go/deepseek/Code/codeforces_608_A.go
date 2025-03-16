package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a new reader from standard input
	reader := bufio.NewReader(os.Stdin)
	
	// Reading the first line of input and storing the number of test cases and the target sum
	var n, s int
	fmt.Fscan(reader, &n, &s)
	
	// Initializing a variable c to 0
	c := 0
	
	// Iterating through the test cases using a for loop
	for i := 0; i < n; i++ {
		// Reading the start and end time of each activity from the input
		var f, t int
		fmt.Fscan(reader, &f, &t)
		
		// Calculating the difference between the end time and the difference between the target sum and start time
		x := t - (s - f)
		
		// Updating the variable c with the maximum value of x calculated in the current iteration
		if x > c {
			c = x
		}
	}
	
	// Printing the final answer which is the sum of the target sum and the maximum overlap calculated
	fmt.Println(s + c)
}

