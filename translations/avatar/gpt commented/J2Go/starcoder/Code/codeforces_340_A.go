package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin
	line, err := reader.ReadString('\n')
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Split the input into individual integers
	line = strings.TrimSuffix(line, "\n")
	nums := strings.Split(line, " ")

	// Convert the strings to integers
	x, err := strconv.ParseInt(nums[0], 10, 64)
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}
	y, err := strconv.ParseInt(nums[1], 10, 64)
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}
	a, err := strconv.ParseInt(nums[2], 10, 64)
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}
	b, err := strconv.ParseInt(nums[3], 10, 64)
	if err!= nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Initialize variables for calculations
	j := int64(2)
	i := int64(0)
	x1 := int64(0)
	y1 := int64(0)
	c := int64(0)
	ans := true

	// Determine the maximum of x and y
	c = int64(math.Max(float64(x), float64(y)))

	// Check if the maximum value exceeds the upper bound b
	if c > b {
		fmt.Println("0") // Output 0 if no valid multiples exist
		ans = false // Set answer flag to false
	}

	// Loop to find the least common multiple (LCM) of x and y
	for c%int64(math.Min(float64(x), float64(y)))!= 0 && ans {
		// Multiply by j to find the next multiple
		if x > y {
			c = x * j // Calculate next multiple of x
			j++
		} else {
			c = y * j // Calculate next multiple of y
			j++
		}

		// Check if the calculated multiple exceeds the upper bound b
		if c > b {
			fmt.Println("0") // Output 0 if no valid multiples exist
			ans = false // Set answer flag to false
			break // Exit the loop
		}
	}

	// If a valid multiple was found within the bounds
	if ans {
		count := int64(0) // Initialize count of valid multiples
		// Find the first multiple of c within the range [a, b]
		for i = a; i <= b; i++ {
			if i%c == 0 {
				break // Break when a multiple is found
			}
		}

		// Check if a valid multiple was found within the range
		if i!= b+1 {
			// Calculate the number of multiples of c in the range [a, b]
			fmt.Println(((b - i) / c) + 1)
		} else {
			fmt.Println("0") // Output 0 if no multiples found
		}
	}
}

