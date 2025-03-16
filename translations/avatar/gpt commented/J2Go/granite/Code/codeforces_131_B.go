
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	scan := bufio.NewScanner(os.Stdin)
	
	// Read the number of integers to process
	scan.Scan()
	n, _ := strconv.Atoi(scan.Text())
	
	// Initialize an array to count occurrences of integers in the range [-10, 10]
	cnt := make([]int, 21) // Array size is 21 to accommodate indices from 0 to 20
	
	// Loop to read n integers and count their occurrences
	for i := 0; i < n; i++ {
		// Increment the count for the input integer adjusted by +10 to handle negative values
		scan.Scan()
		num, _ := strconv.Atoi(scan.Text())
		cnt[num+10]++
	}
	
	// Variable to store the final result
	res := int64(0)
	
	// Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
	for i := 0; i < 10; i++ {
		// Multiply the counts of i and (20 - i) and add to the result
		res += int64(cnt[i]) * int64(cnt[20-i])
	}
	
	// Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
	res += int64(cnt[10]) * int64(cnt[10]-1) / 2
	
	// Output the final result
	fmt.Println(res)
}

