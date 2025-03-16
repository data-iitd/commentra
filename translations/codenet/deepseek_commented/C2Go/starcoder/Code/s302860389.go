<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	// Array to store the input numbers as characters
	inputNumbers := make([]byte, 5)
	// Temporary array to hold individual digits
	temp := make([]byte, 2)
	// Integer variables to store the digits
	var a, b, c, d int
	// Variable to store the intermediate results
	var sum int
	// Array to store the operators
	symbols := make([]byte, 3)

	// Read a string of four characters from the input
	fmt.Scanf("%s", &inputNumbers)

	// Initialize the second element of temp to the null character
	temp[1] = byte(0)

	// Extract each digit from inputNumbers and convert it to an integer
	temp[0] = inputNumbers[0]
	a = int(temp[0] - '0')
	temp[0] = inputNumbers[1]
	b = int(temp[0] - '0')
	temp[0] = inputNumbers[2]
	c = int(temp[0] - '0')
	temp[0] = inputNumbers[3]
	d = int(temp[0] - '0')

	// Nested loop structure to explore all combinations of addition and subtraction
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				// Choose the operation based on the value of i
				if i == 0 {
					sum = a + b
					symbols[0] = '+'
				} else {
					sum = a - b
					symbols[0] = '-'
				}

				// Choose the operation based on the value of j
				if j == 0 {
					sum = sum + c
					symbols[1] = '+'
				} else {
					sum = sum - c
					symbols[1] = '-'
				}

				// Choose the operation based on the value of k
				if k == 0 {
					sum = sum + d
					symbols[2] = '+'
				} else {
					sum = sum - d
					symbols[2] = '-'
				}

				// Check if the sum equals 7
				if sum == 7 {
					// Print the expression if the sum is 7
					fmt.Printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)

					// Exit the program with a return value of 0
					return
				}
			}
		}
	}

	// Return 0 if no combination results in a sum of 7
	return
}

