
package main

import "fmt"

func main() {
	var n int // Step 1: Read the input values
	fmt.Scan(&n) // The integer `n` represents the length of the string `s`.
	var s string
	fmt.Scan(&s) // The string `s` is read from the standard input.
	cnt := 0 // Step 2: Initialize a counter
	for i := 0; i < n; i++ { // Step 3: Iterate through the string
		cnt++ // Increment the counter for each distinct character
		j := i + 1
		for ; j < n; j++ { // Step 4: Count distinct characters
			if s[i]!= s[j] { // Check if the current character is different from the next one
				break // If a different character is found, break the inner loop
			}
		}
		i = j - 1 // Step 5: Update the loop index
	}
	fmt.Println(cnt) // Step 6: Output the result
}

