
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Initialize scanner to read input from the standard input
	sc := bufio.NewScanner(os.Stdin)

	// Read the first two integers from the standard input
	var N, K int
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	K, _ = strconv.Atoi(sc.Text())

	// Allocate an integer array of size N to store the input elements
	S := make([]int, N)

	// Read the remaining elements of the array from the standard input
	for i := 0; i < N; i++ {
		sc.Scan()
		S[i], _ = strconv.Atoi(sc.Text())
	}

	// Initialize variables for calculating the answer
	var temp int
	ans := 1000000000

	// Check the special case when the size of the sliding window is 1
	if K == 1 {
		// Iterate through the array to find the minimum absolute value
		for i := 0; i < N; i++ {
			temp = S[i]
			ans = int(math.Min(float64(ans), float64(math.Abs(temp))))
		}

		// Print the answer
		fmt.Println(ans)
	} else if N-K != 0 { // Check the case when the size of the sliding window is not equal to the size of the array
		// Initialize variables for calculating the minimum and maximum elements in the sliding window
		var min, max int

		// Iterate through all possible positions of the sliding window
		for i := 0; i <= N-K; i++ {
			// Find the minimum and maximum elements in the current sliding window
			min = S[i]
			max = S[i+K-1]

			// Calculate the sum of the absolute values of the minimum and maximum elements
			// and update the answer if necessary
			if min < 0 && max > 0 {
				temp = 2*math.Abs(float64(min)) + max
			} else {
				temp = int(math.Max(float64(math.Abs(min)), float64(math.Abs(max))))
			}
			ans = int(math.Min(float64(ans), float64(temp)))
		}

		// Print the answer
		fmt.Println(ans)
	} else { // Check the case when the size of the sliding window is equal to the size of the array
		// Find the minimum and maximum elements in the array
		min = S[0]
		max = S[N-1]

		// Calculate the sum of the absolute values of the minimum and maximum elements
		// and print the answer directly
		if min < 0 && max > 0 {
			fmt.Println(int(math.Min(2*math.Abs(float64(min))+max, math.Abs(float64(min))+2*max)))
		} else {
			fmt.Println(int(math.Max(float64(math.Abs(min)), float64(math.Abs(max)))))
		}
	}

	// Close the scanner to release the system resources
	sc.Close()
}

