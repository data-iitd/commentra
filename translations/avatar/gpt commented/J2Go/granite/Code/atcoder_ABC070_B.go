
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read four integers from input
	a, _ := reader.ReadString('\n')
	b, _ := reader.ReadString('\n')
	c, _ := reader.ReadString('\n')
	d, _ := reader.ReadString('\n')

	// Convert the strings to integers
	aInt, _ := strconv.Atoi(strings.TrimSpace(a))
	bInt, _ := strconv.Atoi(strings.TrimSpace(b))
	cInt, _ := strconv.Atoi(strings.TrimSpace(c))
	dInt, _ := strconv.Atoi(strings.TrimSpace(d))

	// Check conditions to determine the output
	if cInt > bInt {
		// If c is greater than b, output 0
		fmt.Fprintln(writer, 0)
	} else if aInt > dInt {
		// If a is greater than d, output 0
		fmt.Fprintln(writer, 0)
	} else if aInt < cInt {
		// If a is less than c, calculate and output the difference
		fmt.Fprintln(writer, min(bInt, dInt)-cInt)
	} else {
		// Create a list to hold the four integers
		l := []int{aInt, bInt, cInt, dInt}

		// Sort the list to find the second largest and third largest values
		sort.Ints(l)

		// Output the difference between the second largest and third largest values
		fmt.Fprintln(writer, l[2]-l[1])
	}
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Function to find the minimum of three integers
func min3(a, b, c int) int {
	return min(min(a, b), c)
}

// Function to find the maximum of three integers
func max3(a, b, c int) int {
	return max(max(a, b), c)
}

// Function to find the minimum of four integers
func min4(a, b, c, d int) int {
	return min(min(a, b), min(c, d))
}

// Function to find the maximum of four integers
func max4(a, b, c, d int) int {
	return max(max(a, b), max(c, d))
}

// Function to find the minimum of five integers
func min5(a, b, c, d, e int) int {
	return min(min(a, b), min(min(c, d), e))
}

// Function to find the maximum of five integers
func max5(a, b, c, d, e int) int {
	return max(max(a, b), max(max(c, d), e))
}

// Function to find the minimum of six integers
func min6(a, b, c, d, e, f int) int {
	return min(min(a, b), min(min(min(c, d), e), f))
}

// Function to find the maximum of six integers
func max6(a, b, c, d, e, f int) int {
	return max(max(a, b), max(max(max(c, d), e), f))
}

// Function to find the minimum of seven integers
func min7(a, b, c, d, e, f, g int) int {
	return min(min(a, b), min(min(min(min(c, d), e), f), g))
}

// Function to find the maximum of seven integers
func max7(a, b, c, d, e, f, g int) int {
	return max(max(a, b), max(max(max(max(c, d), e), f), g))
}

// Function to find the minimum of eight integers
func min8(a, b, c, d, e, f, g, h int) int {
	return min(min(a, b), min(min(min(min(min(c, d), e), f), g), h))
}

// Function to find the maximum of eight integers
func max8(a, b, c, d, e, f, g, h int) int {
	return max(max(a, b), max(max(max(max(max(c, d), e), f), g), h))
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

// Function to find the product of n integers
func productN(a...int) int {
	product := 1
	for _, v := range a {
		product *= v
	}
	return product
}

// Function to find the minimum of n integers
func minN(a...int) int {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

// Function to find the maximum of n integers
func maxN(a...int) int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return max
}

// Function to find the sum of n integers
func sumN(a...int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return s