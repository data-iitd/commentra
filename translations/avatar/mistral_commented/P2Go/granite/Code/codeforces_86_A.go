
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read two integers as input and store them in variables 'l' and 'r' respectively
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	l, _ := strconv.Atoi(parts[0])
	r, _ := strconv.Atoi(parts[1])

	// Initialize current number to 'r'
	curr := r

	// Initialize sum variable's' to 0
	s := 0

	// While 'curr' is not zero, perform the following operations
	for curr!= 0 {
		// Increment the sum's' by 1
		s++

		// Calculate the power of 10 raised to the value of's' and store it in 'first'
		first := int(math.Pow(10, float64(s)))

		// Calculate half of 'first' and store it in'second'
		second := first / 2

		// Initialize 'ans' with a negative value
		ans := -1

		// Iterate through the list containing 'l', 'r', 'first', and'second'
		for _, i := range []int{l, r, first, second} {
			// If 'i' lies within the range of 'l' and 'r', update 'curr' and'rev'
			if i >= l && i <= r {
				curr = i
				rev := ""
				// Reverse the digits of 'curr' and store it in'rev'
				for _, k := range fmt.Sprintf("%d", curr) {
					rev += fmt.Sprintf("%d", 9-int(k[0]-'0'))
				}

				// Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
				ans = int(math.Max(float64(ans), float64(strconv.Atoi(rev)*curr)))
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}
