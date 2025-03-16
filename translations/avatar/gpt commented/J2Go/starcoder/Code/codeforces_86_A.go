package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Method to calculate the number of digits in a given number
func power(a int64) int {
	res := 0
	// Count the number of digits by dividing the number by 10 until it becomes 0
	for a > 0 {
		res++
		a = a / 10
	}
	return res
}

// Method to calculate the product of a number and the difference between the largest number with the same number of digits and the number itself
func mult(a int64) int64 {
	pow := power(a) // Get the number of digits in 'a'
	max := int64(0)
	// Create the largest number with the same number of digits as 'a' (all 9s)
	for j := 0; j < pow; j++ {
		max = max*10 + 9
	}
	// Return the product of 'a' and the difference between the largest number and 'a'
	return a * (max - a)
}

func main() {
	in := bufio.NewReader(os.Stdin) // Create a Reader object for input
	l, _ := strconv.ParseInt(strings.TrimSpace(readLine(in)), 10, 64)
	r, _ := strconv.ParseInt(strings.TrimSpace(readLine(in)), 10, 64)
	res := int64(0) // Variable to store the maximum result
	maxxes := make([]int64, 10) // Array to store maximum products for numbers with different digit lengths
	temp := int64(0)

	// Precompute maximum products for numbers with up to 10 digits
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Create the largest number with i+1 digits (all 9s)
		maxxes[i] = temp/2*(temp-temp/2) // Calculate the maximum product for this digit length
	}

	// Calculate the maximum product for the lower bound 'l'
	res = int64(max(int(mult(l)), int(res)))
	// Calculate the maximum product for the upper bound 'r'
	res = int64(max(int(mult(r)), int(res)))
	temp = int64(0)

	// Check for numbers formed by all 9s and see if they lie within the range [l, r]
	for i := 0; i < 10; i++ {
		temp = temp*10 + 9 // Create the largest number with i+1 digits (all 9s)
		// If the half of this number is within the range, consider its maximum product
		if l <= temp/2 && temp/2 <= r {
			res = int64(max(int(maxxes[i]), int(res)))
		}
	}

	// Output the maximum product found
	fmt.Println(res)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

