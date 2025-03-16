
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Process each test case
	for n > 0 {
		// Read the values of p and q
		p, _ := strconv.Atoi(readLine(reader))
		q, _ := strconv.Atoi(readLine(reader))

		// Calculate the length l based on the Euclidean distance from the origin
		l := int(math.Sqrt(float64(p*p + q*q)))

		// Initialize a flag to check if the current case is prime
		isPrime := true

		// Check all combinations of i and j within the range [0, l)
		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				// Calculate the sum of squares of i and j
				x := i*i + j*j

				// Skip values of x that are not in the valid range
				if x <= 1 || x >= p*p+q*q {
					continue
				}

				// Check the conditions for primality based on the given formula
				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isPrime = false // Set isPrime to false if conditions are met
				}
			}
		}

		// Output "P" if prime, otherwise output "C"
		fmt.Println(ifelse(isPrime, "P", "C"))

		n--
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

func ifelse(condition bool, trueValue string, falseValue string) string {
	if condition {
		return trueValue
	}
	return falseValue
}

