
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of elements (n), number of selected elements (k),
	// lower bound (l), upper bound (r), total sum (sAll), and sum of selected elements (sk)
	var n, k, l, r, sAll, sk int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	l, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	r, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	sAll, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	sk, _ = strconv.Atoi(scanner.Text())

	// Call the getPoints function to calculate the points distribution
	ans := getPoints(n, k, l, r, sAll, sk)

	// Print the resulting points distribution
	fmt.Println(strings.Join(ans, " "))
}

func getPoints(n, k, l, r, sAll, sk int) []string {
	// Initialize an array to hold the points for each element
	ans := make([]string, n)

	// Fill the array with the minimum value l
	for i := 0; i < n; i++ {
		ans[i] = strconv.Itoa(l)
	}

	// Adjust the total sum by subtracting the sum of selected elements and the minimum values
	sAll -= sk + (n - k) * l

	// Adjust the sum of selected elements by subtracting the minimum values
	sk -= k * l

	// Distribute the remaining points to the last k elements
	for sk > 0 {
		idx := n - 1
		for idx >= n-k && sk > 0 {
			ans[idx] = strconv.Itoa(strconv.Atoi(ans[idx]) + 1) // Increment the points for the selected elements
			sk-- // Decrease the remaining points to distribute
		}
	}

	// Distribute the remaining total sum to the first n-k elements
	for sAll > 0 {
		idx := 0
		for idx < n-k && sAll > 0 {
			ans[idx] = strconv.Itoa(strconv.Atoi(ans[idx]) + 1) // Increment the points for the non-selected elements
			sAll-- // Decrease the remaining total sum to distribute
		}
	}

	// Return the final points distribution
	return ans
}

// END-OF-CODE