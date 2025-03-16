package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements (N) and the number of comparisons (M)
	var N int
	var M int64
	sc.Scan()
	N, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	M, _ = strconv.ParseInt(sc.Text(), 10, 64)

	// Initialize an array to hold the heights and a boolean array to track valid heights
	H := make([]int64, N)
	ans := make([]bool, N)

	// Read the heights and initialize the ans array to true
	for i := 0; i < N; i++ {
		sc.Scan()
		H[i], _ = strconv.ParseInt(sc.Text(), 10, 64) // Read the height for each element
		ans[i] = true                                 // Assume all heights are valid initially
	}

	// Process M comparisons between pairs of heights
	for i := 0; i < M; i++ {
		var temp1 int
		var temp2 int
		sc.Scan()
		temp1, _ = strconv.Atoi(sc.Text()) // Read the first index for comparison
		sc.Scan()
		temp2, _ = strconv.Atoi(sc.Text()) // Read the second index for comparison

		// Compare the heights and update the ans array based on the comparison results
		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false // temp1 is shorter, mark it as invalid
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false // temp2 is shorter, mark it as invalid
		} else {
			// If heights are equal, mark both as invalid
			ans[temp1-1] = false
			ans[temp2-1] = false
		}
	}

	// Count the number of valid heights
	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++ // Increment count for each valid height
		}
	}

	// Output the count of valid heights
	fmt.Println(ans2)
}

