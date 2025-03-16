
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a string of numbers: ")
	inputNumbers, _ := reader.ReadString('\n')
	inputNumbers = strings.TrimSpace(inputNumbers)

	temp := make([]byte, 2)
	a, _ := strconv.Atoi(string(inputNumbers[0]))
	b, _ := strconv.Atoi(string(inputNumbers[1]))
	c, _ := strconv.Atoi(string(inputNumbers[2]))
	d, _ := strconv.Atoi(string(inputNumbers[3]))

	for i := 0; i < 2; i++ { // Loop for the first operation (a + b or a - b)
		for j := 0; j < 2; j++ { // Loop for the second operation (result + c or result - c)
			for k := 0; k < 2; k++ { // Loop for the third operation (result + d or result - d)
				var sum int
				symbols := make([]byte, 3)

				// Determine the first operation (addition or subtraction with a and b)
				if i == 0 {
					sum = a + b // Perform addition
					symbols[0] = '+' // Store the symbol used
				} else {
					sum = a - b // Perform subtraction
					symbols[0] = '-' // Store the symbol used
				}

				// Determine the second operation (addition or subtraction with c)
				if j == 0 {
					sum = sum + c // Perform addition
					symbols[1] = '+' // Store the symbol used
				} else {
					sum = sum - c // Perform subtraction
					symbols[1] = '-' // Store the symbol used
				}

				// Determine the third operation (addition or subtraction with d)
				if k == 0 {
					sum = sum + d // Perform addition
					symbols[2] = '+' // Store the symbol used
				} else {
					sum = sum - d // Perform subtraction
					symbols[2] = '-' // Store the symbol used
				}

				// Check if the calculated sum equals 7
				if sum == 7 {
					// Print the expression that results in 7
					fmt.Printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)
					return // Exit the program after finding the first valid expression
				}
			}
		}
	}
}

