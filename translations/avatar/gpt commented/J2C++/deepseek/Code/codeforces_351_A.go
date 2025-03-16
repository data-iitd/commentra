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
	// Initialize BufferedReader to read input from standard input
	reader := bufio.NewReader(os.Stdin)
	
	// Read the number of elements (n)
	n, _ := strconv.Atoi(readLine(reader))
	
	// Read the input line containing the numbers
	input, _ := reader.ReadString('\n')
	
	// Tokenize the input line containing the numbers
	tokens := strings.Fields(input)
	
	// Array to store the numbers and variables for calculations
	arr := make([]float64, 2 * n)
	non_int := 0 // Counter for non-integer values
	sum_before := 0.0 // Variables to store sums
	sum := 0.0
	
	// Loop through the input numbers
	for i := 0; i < 2 * n; i++ {
		// Parse the next number from the input
		num, _ := strconv.ParseFloat(tokens[i], 64)
		
		// Accumulate the total sum of the numbers
		sum_before += num
		
		// Check if the number is non-integer and update the counter
		if num != math.Floor(num) {
			non_int++
		}
		
		// Accumulate the sum of the integer parts of the numbers
		sum += math.Floor(num)
		
		// Store the number in the array
		arr[i] = num
	}
	
	// Calculate the maximum possible sum considering non-integer values
	max_sum := math.Min(float64(n), float64(non_int)) + sum
	
	// Calculate the minimum possible sum considering non-integer values
	min_sum := math.Max(0, float64(non_int) - float64(n)) + sum
	
	var ans float64 // Variable to store the final answer
	
	// Determine the answer based on the calculated sums
	if min_sum > sum_before {
		ans = min_sum - sum_before // Case where min_sum is greater than the total sum
	} else if max_sum < sum_before {
		ans = sum_before - max_sum // Case where max_sum is less than the total sum
	} else {
		// Case where the total sum is between min_sum and max_sum
		x := sum_before - math.Floor(sum_before)
		ans = math.Min(1 - x, x) // Calculate the minimum distance to the nearest integer
	}
	
	// Print the final answer formatted to three decimal places
	fmt.Printf("%.3f\n", ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
