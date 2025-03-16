
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Initialize scanner object to read input from the console
func main() {
	scan := bufio.NewScanner(os.Stdin) // Create a new Scanner object

	// Read the number of test cases from the console
	n, _ := strconv.Atoi(scan.Text())

	// Define the maximum size of the array to avoid array out of bounds exception
	N := 100005

	// Initialize an array to store the count of each number
	cnt := make([]int, N)

	// Read the numbers one by one and update the count array accordingly
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(scan.Text()) // Read the next number
		cnt[num+10]++ // Increment the count of the number
	}

	// Calculate the result using the given formula
	res := 0
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i] // Calculate the sum of products of pairs of numbers with absolute difference i
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2 // Calculate the sum of squares of numbers equal to 10 and add half of it

	// Print the result to the console
	fmt.Println(res)
}

