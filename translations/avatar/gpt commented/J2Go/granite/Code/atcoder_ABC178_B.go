
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to compute (x^y) % mod using modular exponentiation
func modPower(x, y, mod int) int {
	res := 1
	x %= mod // Reduce x modulo mod
	if x == 0 {
		return 0 // If x is 0, return 0
	}
	for y > 0 {
		if y%2 == 1 { // If y is odd, multiply x with result
			res = (res * x) % mod
		}
		y = y >> 1 // Divide y by 2
		x = (x * x) % mod // Square x
	}
	return res // Return the final result
}

// Function to read the next integer from input
func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

// Function to read the next long from input
func readLong() int64 {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

// Function to read the next double from input
func readDouble() float64 {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

// Function to read the next line from input
func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Main method to execute the program
func main() {
	a := make([]int64, 4) // Array to hold four long integers

	// Read four long integers from input
	for i := 0; i < 4; i++ {
		a[i] = readLong()
	}

	// Calculate and print the maximum product of pairs from the array
	fmt.Println(int(
		math.Max(float64(a[0]*a[2]),
			math.Max(float64(a[1]*a[3]),
				math.Max(float64(a[0]*a[3]), float64(a[1]*a[2]))))))
}

// END-OF-CODE