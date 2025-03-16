/*
これを入れて実行
go run code.go
 */

package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

// Function to check if first pair has greater second value than second pair
func greaterSecond(f, s pair) bool {
	return f.second > s.second
}

// Function to find the greatest common divisor of two numbers
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

//-----------------------Main function-----------------------
func main() {
	// Input the number of digits in binary representation
	var n int
	fmt.Scan(&n)

	// Initialize an empty string 's' to store binary representation
	s := ""

	// Check if the number is zero and print '0' if it is
	if n == 0 {
		fmt.Println("0")
		return
	}

	// Iterate through the number from the least significant bit to the most significant bit
	i := 1
	for n != 0 {
		// If the number is even, add '0' to the binary representation
		if n%2 == 0 {
			s += "0"
		} else {
			// If the number is odd, add '1' to the binary representation
			s += "1"
		}

		// Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
		n -= int(math.Abs(float64(n % 2)))

		// Update the number by dividing it by -2 (since we subtracted the remainder in the previous step, we need to divide by -2 to get the next number)
		n /= -2
	}

	// Reverse the binary representation and print it
	reverse := []rune(s)
	for i, j := 0, len(reverse)-1; i < j; i, j = i+1, j-1 {
		reverse[i], reverse[j] = reverse[j], reverse[i]
	}
	fmt.Println(string(reverse))
}


Translate the above Go code to Python and end with comment "