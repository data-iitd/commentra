<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner to read from stdin
	scanner := bufio.NewScanner(os.Stdin)

	// Initialize an empty map'm' to store the multipliers
	m := make(map[int]int)

	// Initialize the multipliers
	m[10] = 1
	m[50] = 1
	m[100] = 1
	m[500] = 1

	// Main loop to read the input money and calculate the change
	for scanner.Scan() {
<<<<<<< HEAD
		// Initialize variables'sum' and 'num'
		sum := 0
		num := make(map[int]int)

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for _, v := range strings.Fields(scanner.Text()) {
			i, _ := strconv.Atoi(v)
			sum += i * m[i]
			num[i] = num[i] + 1
		}

		// Calculate the change
		change := sum - i

		// Adjust the numbers to get the exact change
		for i := 500; i >= 10; i /= 10 {
			// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if change%i == 0 {
				num[i] = num[i] - change/i
				change = change%i
=======
		// Initialize a string variable 'line' to store the input line
		line := scanner.Text()

		// Split the input line into a slice of strings
		line = strings.Split(line, " ")

		// Convert the first element of the slice to an integer and store it in a variable'money'
		money, _ := strconv.Atoi(line[0])

		// Initialize a slice of integers 'num' to store the numbers
		num := make([]int, 4)

		// Initialize a variable'sum' to store the sum of the products of each number and its corresponding multiplier
		sum := 0

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for i := 0; i < 4; i++ {
			// Convert the i-th element of the slice to an integer and store it in a variable 'n'
			n, _ := strconv.Atoi(line[i+1])

			// Calculate the product and add it to the sum
			sum += n * m[n]

			// Store the number in the i-th element of the slice 'num'
			num[i] = n
		}

		// Calculate the change
		change := sum - money

		// Adjust the numbers to get the exact change
		for i := 3; i >= 0; i-- {
			// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if change/m[i] > 0 {
				num[i] -= change / m[i]
				change %= m[i]
>>>>>>> 98c87cb78a (data updated)
			}
		}

		// Print the numbers that still have a positive value
<<<<<<< HEAD
		for i := 10; i <= 500; i *= 10 {
			if num[i] > 0 {
				fmt.Printf("%d %d\n", i, num[i])
=======
		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Printf("%d %d\n", m[i], num[i])
>>>>>>> 98c87cb78a (data updated)
			}
		}
	}
}

