package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to find the greatest common divisor of two numbers
func getGCD(a, b int) int {
	if b == 0 {
		return a
	}
	return getGCD(b, a%b)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ := strconv.Atoi(scanner.Text())

	a := make([]int, n)

	// Initializing the array a with input values
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		a[i] /= 2
	}

	lcd := 1

	// Finding the least common multiple of all array elements
	for i := 0; i < n; i++ {
		gcd := getGCD(lcd, a[i])
		lcd = lcd * a[i] / gcd

		// Checking if lcm is greater than m
		if lcd > m {
			fmt.Println(0)
			return
		}
	}

	// Checking if any array element is a factor of lcm
	for i := 0; i < n; i++ {
		if (lcd / a[i]) % 2 == 0 {
			fmt.Println(0)
			return
		}
	}

	// Printing the result
	fmt.Println((m/lcd + 1) / 2)
}

