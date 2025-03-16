package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Step 1: Take an integer input `n`

	var number []int
	var digit int
	for i := 0; i < n; i++ {
		fmt.Scan(&digit) // Step 1: Take a list of integers `number`
		number = append(number, digit)
	}

	var h1, h2, x int

	// Step 4: Enter a for loop to iterate over each digit in the number
	for i := 0; i < n; i++ {
		if number[i] != 4 && number[i] != 7 { // Step 5: Check if the current digit is invalid
			fmt.Println("NO") // Step 5: Print "NO" and break the loop if an invalid digit is found
			x = 1             // Step 5: Set `x` to 1
			break             // Step 5: Break out of the loop
		}
		if i < n/2 { // Step 6: Add the digit to `h1` if it's in the first half
			h1 += number[i]
		} else { // Step 6: Add the digit to `h2` if it's in the second half
			h2 += number[i]
		}
	}

	// Step 7: After the loop, check if `x` is still 0 and compare the sums of the first and second halves
	if x == 0 { // Step 7: Check if no invalid digit was found
		if h1 == h2 { // Step 7: Check if the sums are equal
			fmt.Println("YES") // Step 7: Print "YES" if the sums are equal
		} else { // Step 7: Print "NO" if the sums are not equal
			fmt.Println("NO")
		}
	}
}

