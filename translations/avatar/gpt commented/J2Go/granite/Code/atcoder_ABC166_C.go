
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a scanner to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements (N) and the number of comparisons (M)
	N, _ := strconv.Atoi(read(reader))
	M, _ := strconv.ParseInt(read(reader), 10, 64)

	// Initialize an array to hold the heights and a boolean array to track valid heights
	H := make([]int64, N)
	ans := make([]bool, N)

	// Read the heights and initialize the ans array to true
	for i := 0; i < N; i++ {
		H[i], _ = strconv.ParseInt(read(reader), 10, 64)
		ans[i] = true
	}

	// Process M comparisons between pairs of heights
	for i := 0; i < int(M); i++ {
		temp1, _ := strconv.Atoi(read(reader))
		temp2, _ := strconv.Atoi(read(reader))

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

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(str)
}

