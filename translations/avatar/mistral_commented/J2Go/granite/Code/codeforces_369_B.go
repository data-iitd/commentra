

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Reading input values from the user
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	l, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	r, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	sAll, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	sk, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Calling the getPoints() function to get the updated scores of all points
	ans := getPoints(n, k, l, r, sAll, sk)

	// Printing the updated scores of all points
	for _, num := range ans {
		fmt.Print(num, " ") // Printing each updated score followed by a space
	}

	fmt.Println() // Printing a newline after printing all scores
}

func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n) // Initializing a slice ans of size n to store the updated scores of all points

	// Filling the initial scores of all points with the value l
	for i := 0; i < n; i++ {
		ans[i] = l
	}

	// Calculating the remaining score after removing the given k points and segments of length l
	sAll -= sk + (n - k) * l

	// Removing the score of the given k points
	sk -= k * l

	// Finding the indices of the points to be increased in the first while loop
	idx := n - 1
	for sk > 0 && idx >= n-k {
		ans[idx]++ // Increasing the score of the current point by 1
		sk--         // Decreasing the remaining score by 1
		idx--
	}

	// Finding the indices of the points to be increased in the second while loop
	for sAll > 0 {
		idx = 0
		for sAll > 0 && idx < n-k {
			ans[idx]++ // Increasing the score of the current point by 1
			sAll--      // Decreasing the remaining score by 1
			idx++
		}
	}

	// Returning the updated scores of all points as a slice
	return ans
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

These comments should provide a clear understanding of the code and its logical flow.