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
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements (N) and the size of the subset (K)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	K, _ := strconv.Atoi(sc.Text())

	// Initialize an array to store the input integers
	S := make([]int, N)

	// Read N integers into the array S
	for i := 0; i < N; i++ {
		sc.Scan()
		S[i], _ = strconv.Atoi(sc.Text())
	}

	// Initialize temporary variable and answer variable with a large number
	temp := 0
	ans := 1000000000

	// Case when K is 1: Find the minimum absolute value in the array
	if K == 1 {
		for i := 0; i < N; i++ {
			temp = S[i]
			ans = int(math.Min(float64(math.Abs(float64(temp))), float64(ans))) // Update ans with the minimum absolute value
		}
		// Output the result
		fmt.Println(ans)
	}
	// Case when K is not equal to N: Calculate the minimum value based on subsets of size K
	else if N-K!= 0 {
		for i := 0; i <= N-K; i++ {
			min := S[i] // Minimum value in the current subset
			max := S[i+K-1] // Maximum value in the current subset

			// Calculate temp based on the values of min and max
			if min < 0 && max > 0 {
				// If the subset contains both negative and positive values
				temp = int(math.Min(float64(2*(-min)+max), float64((-min)+2*max)))
			} else {
				// If the subset contains only negative or only positive values
				temp = int(math.Max(float64(math.Abs(float64(min))), float64(math.Abs(float64(max)))))
			}

			// Update the answer with the minimum value found
			ans = int(math.Min(float64(ans), float64(temp)))
		}
		// Output the result
		fmt.Println(ans)
	}
	// Case when K is equal to N: Handle the entire array as a single subset
	else {
		min := S[0] // Minimum value in the array
		max := S[N-1] // Maximum value in the array

		// Check if the array contains both negative and positive values
		if min < 0 && max > 0 {
			// Calculate and print the minimum value based on the formula
			fmt.Println(int(math.Min(float64(2*(-min)+max), float64((-min)+2*max))))
		} else {
			// Print the maximum absolute value
			fmt.Println(int(math.Max(float64(math.Abs(float64(min))), float64(math.Abs(float64(max))))))
		}
	}
}

