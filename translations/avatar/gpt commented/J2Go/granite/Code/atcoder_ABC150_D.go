
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the first integer n, which represents the number of elements
	n, _ := strconv.Atoi(reader.ReadLine()[0:1])

	// Read the second integer m, which represents the upper limit
	m, _ := strconv.Atoi(reader.ReadLine()[0:1])

	// Initialize an array to hold the processed values
	a := make([]int, n)

	// Read n integers from input, divide each by 2, and store in array a
	for i := 0; i < n; i++ {
		input, _ := reader.ReadLine()
		a[i], _ = strconv.Atoi(input[0:1]) / 2
	}

	gcd := int64(1) // Initialize the greatest common divisor (gcd) to 1
	lcd := int64(1) // Initialize the least common multiple (lcd) to 1

	// Calculate the least common multiple (lcd) of the array elements
	for i := 0; i < n; i++ {
		gcd = getGCD(lcd, int64(a[i])) // Get the greatest common divisor (gcd) of lcd and current element
		lcd = lcd * int64(a[i]) / gcd // Update lcd using the formula: lcd = (lcd * a[i]) / gcd

		// If lcd exceeds m, print 0 and exit
		if lcd > int64(m) {
			fmt.Println(0)
			return
		}
	}

	// Check if the condition for each element in the array is satisfied
	for i := 0; i < n; i++ {
		// If lcd divided by the current element is even, print 0 and exit
		if (lcd / int64(a[i]))%2 == 0 {
			fmt.Println(0)
			return
		}
	}

	// Calculate and print the final result based on the value of m and lcd
	fmt.Println((int64(m)/lcd+1)/2)
}

// Method to compute the greatest common divisor (gcd) using recursion
func getGCD(a, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return getGCD(b, a%b) // Recursive call to find gcd
	}
}

// END-OF-CODE