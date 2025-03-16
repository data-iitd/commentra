package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a new Scanner object to read input from the user
	// Note: In Go, there is no built-in Scanner like in Java, so we use fmt.Scan to read input
	var number int64
	fmt.Scan(&number)
	
	// Initialize two variables, ans and value, to -1 and 0, respectively
	var ans int64 = -1
	var value int64 = 0
	
	// Set a mask variable to 2
	mask := 2
	
	// The code enters a while loop that continues as long as value is less than the input number
	for value < number {
		// Convert the mask value to a binary string, remove the first character, and store the result in the s variable
		s := strconv.FormatInt(int64(mask), 2)[1:]
		mask++
		
		// Count the number of zeros in the binary string and store it in the zeros variable
		zeros := 0
		for _, c := range s {
			if c == '0' {
				zeros++
			}
		}
		
		// If the number of zeros is not equal to the number of ones, skip the rest of the loop
		if zeros != len(s) - zeros {
			continue
		}
		
		// Replace all zeros with 4 and all ones with 7 in the binary string and convert it back to a long integer
		s = strings.ReplaceAll(s, "0", "4")
		s = strings.ReplaceAll(s, "1", "7")
		value, _ = strconv.ParseInt(s, 10, 64)
	}
	
	// Print the value variable
	fmt.Println(value)
}
