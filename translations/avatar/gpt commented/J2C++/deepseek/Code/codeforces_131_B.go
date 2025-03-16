package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of integers to process
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize an array to count occurrences of integers in the range [-10, 10]
	cnt := make([]int64, 21) // Array size is 21 to accommodate indices from 0 to 20
	
	// Loop to read n integers and count their occurrences
	for i := 0; i < n; i++ {
		scanner.Scan()
		// Increment the count for the input integer adjusted by +10 to handle negative values
		val := scanner.Text()
		intVal, _ := fmt.Sscan(val, &val)
		cnt[intVal + 10]++
	}
	
	// Variable to store the final result
	var res int64 = 0
	
	// Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
	for i := 0; i < 10; i++ {
		// Multiply the counts of i and (20 - i) and add to the result
		res += cnt[int64(i)] * cnt[int64(20 - i)]
	}
	
	// Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
	res += (cnt[10] * (cnt[10] - 1)) / 2
	
	// Output the final result
	fmt.Println(res)
}
