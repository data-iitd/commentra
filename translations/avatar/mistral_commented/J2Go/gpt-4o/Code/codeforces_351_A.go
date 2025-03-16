package main

import (
	"bufio" // Importing required Go package for buffered I/O
	"fmt"   // Importing required Go package for formatted I/O
	"math"  // Importing required Go package for mathematical functions
	"os"    // Importing required Go package for OS functions
	"strconv" // Importing required Go package for string conversion
	"strings" // Importing required Go package for string manipulation
)

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader to read input from standard input

	// Reading the number of test cases
	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	// Reading the elements of the array
	arrStr, _ := reader.ReadString('\n')
	arrStr = strings.TrimSpace(arrStr)
	arrTokens := strings.Split(arrStr, " ")
	arr := make([]float64, 2*n) // Creating a slice to store the array elements
	nonInt := 0                 // Initializing variables
	sumBefore := 0.0
	sum := 0.0

	// Iterating through the array elements and performing the required operations
	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(arrTokens[i], 64) // Parsing the current number
		sumBefore += num                               // Adding the current number to the sumBefore variable
		if num != math.Floor(num) {                   // Checking if the current number is not an integer
			nonInt++
		}
		sum += math.Floor(num) // Adding the floor value of the current number to the sum variable
		arr[i] = num           // Assigning the current number to the corresponding index of the array
	}

	// Calculating the maximum and minimum sums
	maxSum := math.Min(float64(n), float64(nonInt)) + sum
	minSum := math.Max(0, float64(nonInt)-float64(n)) + sum

	// Calculating the answer based on the given conditions
	var ans float64
	if minSum > sumBefore {
		ans = minSum - sumBefore
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum
	} else {
		x := sumBefore - math.Floor(sumBefore)
		ans = math.Min(1-x, x)
	}

	// Printing the answer
	fmt.Printf("%.3f\n", ans)
}

// <END-OF-CODE>
