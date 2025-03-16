
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables
	var inputNumbers string
	var temp string
	var a, b, c, d int
	var sum int
	var symbols [3]string

	// Read input numbers from user
<<<<<<< HEAD
	fmt.Printf("Enter four integers separated by spaces: ")
=======
	fmt.Println("Enter four integers separated by spaces: ")
>>>>>>> 98c87cb78a (data updated)
	fmt.Scanf("%s", &inputNumbers)

	// Extract each number from input string and convert to integer
	temp = strings.Split(inputNumbers, " ")[0]
	a, _ = strconv.Atoi(temp)
	temp = strings.Split(inputNumbers, " ")[1]
	b, _ = strconv.Atoi(temp)
	temp = strings.Split(inputNumbers, " ")[2]
	c, _ = strconv.Atoi(temp)
	temp = strings.Split(inputNumbers, " ")[3]
	d, _ = strconv.Atoi(temp)

	// Perform arithmetic operations and check for the sum equal to 7
	for i := 0; i < 2; i++ { // outer loop
		for j := 0; j < 2; j++ { // middle loop
			for k := 0; k < 2; k++ { // inner loop
				// Assign symbols based on the position of current number
				if i == 0 {
					sum = a + b
					symbols[0] = "+"
				} else {
					sum = a - b
					symbols[0] = "-"
				}

				if j == 0 {
					sum = sum + c
					symbols[1] = "+"
				} else {
					sum = sum - c
					symbols[1] = "-"
				}

				if k == 0 {
					sum = sum + d
					symbols[2] = "+"
				} else {
					sum = sum - d
					symbols[2] = "-"
				}

				// Check if the sum is equal to 7
				if sum == 7 {
					fmt.Printf("%d%c%d%c%d%c%d = 7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)

					// If sum is equal to 7, exit the loop and return 0
					os.Exit(0)
				}
			}
		}
	}

	// If no combination of four numbers results in a sum of 7, return 0
	os.Exit(0)
}

