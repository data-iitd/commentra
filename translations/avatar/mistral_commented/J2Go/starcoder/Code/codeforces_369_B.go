
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Split(bufio.ScanWords)

	// Reading input values from the user
	n, _ := strconv.Atoi(scan.Text())
	k, _ := strconv.Atoi(scan.Text())
	l, _ := strconv.Atoi(scan.Text())
	r, _ := strconv.Atoi(scan.Text())
	sAll, _ := strconv.Atoi(scan.Text())
	sk, _ := strconv.Atoi(scan.Text())

	// Calling the getPoints() method to get the updated scores of all points
	ans := getPoints(n, k, l, r, sAll, sk)

	// Printing the updated scores of all points
	for _, num := range ans {
		fmt.Print(num, " ") // Printing each updated score followed by a space
	}

	fmt.Println() // Printing a newline after printing all scores
}

// getPoints() returns the updated scores of all points
func getPoints(n, k, l, r, sAll, sk int) []int {
	ans := make([]int, n) // Initializing an integer array ans of size n to store the updated scores of all points

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
	for sk > 0 && idx >= n - k {
		ans[idx]++ // Increasing the score of the current point by 1
		sk--        // Decreasing the remaining score by 1
		idx--       // Decreasing the index by 1
	}

	// Finding the indices of the points to be increased in the second while loop
	for sAll > 0 {
		idx = 0
		for sAll > 0 && idx < n - k {
			ans[idx]++ // Increasing the score of the current point by 1
			sAll--     // Decreasing the remaining score by 1
			idx++      // Increasing the index by 1
		}
	}

	// Returning the updated scores of all points as an array
	return ans
}

