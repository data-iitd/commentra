
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize variables
	n := nextInt()
	rt := int(math.Sqrt(float64(n))) // Calculate the square root of n

	// Initialize minimum factor with a large value
	minf := 100

	// Check divisibility for numbers from 1 to the square root of n
	for i := 1; i < rt+1; i++ {
		// Check if n is divisible by i
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}

	// Print the result
	fmt.Println(minf)
}

const size = 1000000

var reader = bufio.NewReaderSize(os.Stdin, size)

// Function to read a line from standard input
func nextLine() string {
	// Initialize line and buffer variables
	line, buffer []byte
	isPrefix := true
	var err error

	// Read line until a complete line is obtained
	for isPrefix {
		line, isPrefix, err = reader.ReadLine()
		if err != nil {
			panic(err)
		}
		buffer = append(buffer, line...)
	}

	// Return the line as a string
	return string(buffer)
}

// Function to read a single string from standard input
func nextString() string {
	return nextLine()
}

// Function to read an array of strings from standard input
func nextStringArray() []string {
	return strings.Split(nextLine(), " ")
}

// Function to read an integer from standard input
func nextInt() int {
	// Read a line from standard input and convert it to an integer
	n, _ := strconv.Atoi(nextLine())
	return n
}

// Function to read an array of integers from standard input
func nextIntArray() []int {
	// Read a line from standard input and split it into an array of strings
	s := strings.Split(nextLine(), " ")

	// Initialize the result array
	n := len(s)
	a := make([]int, n)

	// Convert each string to an integer and store it in the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(s[i])
	}

	// Return the array
	return a
}

// Function to find the minimum of two integers
func min(i, j int) int {
	// Return the smaller of the two integers
	if i > j {
		return j
	}
	return i
}

// Initialize variables and calculate the square root of n
func main() {
	// Read an integer from standard input and initialize n and rt variables
	n := nextInt()
	rt := int(math.Sqrt(float64(n)))

	// Initialize minimum factor with a large value
	minf := 100

	// Check divisibility for numbers from 1 to the square root of n
	for i := 1; i < rt+1; i++ {
		// Check if n is divisible by i
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}

	// Print the result
	fmt.Println(minf)
}

// Function to read a line from standard input
func nextLine() string {
	// Read a line from standard input and return it as a string
	line, _ := reader.ReadLine()
	return string(line)
}

// Function to find the minimum of two integers
func min(i, j int) int {
	// Return the smaller of the two integers
	if i > j {
		return j
	}
	return i
}

// Function to initialize and check divisibility for numbers from 1 to the square root of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)
		}
	}
}

// Initialize variables and call the checkDivisibility function
func main() {
	// Read an integer from standard input and initialize n variable
	n := nextInt()

	// Initialize minimum factor with a large value
	minf := 100

	// Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	// Print the result
	fmt.Println(minf)
}

// Function to find the minimum number of digits in a divisor of n
func checkDivisibility() {
	rt := int(math.Sqrt(float64(n)))
	for i := 1; i < rt+1; i++ {
		if n%i == 0 {
			// Calculate the number of digits in the divisor
			b := n / i
			ndigit := 0
			for b > 0 {
				b /= 10
				ndigit++
			}
			// Update minimum factor if a divisor with fewer digits is f