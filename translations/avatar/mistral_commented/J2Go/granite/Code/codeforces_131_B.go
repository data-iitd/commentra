

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Initialize scanner object to read input from the console
func main() {
	scan := bufio.NewScanner(os.Stdin) // Create a new Scanner object

	// Read the number of test cases from the console
	scan.Scan()
	n, _ := fmt.Sscanf(scan.Text(), "%d")

	// Define the maximum size of the array to avoid array out of bounds exception
	N := int(1e5+5)

	// Initialize an array to store the count of each number
	cnt := make([]int, 21)

	// Read the numbers one by one and update the count array accordingly
	for i := 0; i < n; i++ {
		scan.Scan()
		num, _ := fmt.Sscanf(scan.Text(), "%d") // Read the next number
		cnt[num+10]++ // Increment the count of the number
	}

	// Calculate the result using the given formula
	res := int64(0)
	for i := 0; i < 10; i++ {
		res += int64(cnt[i]) * int64(cnt[20-i]) // Calculate the sum of products of pairs of numbers with absolute difference i
	}
	res += int64(cnt[10]) * (int64(cnt[10]) - 1) / 2 // Calculate the sum of squares of numbers equal to 10 and add half of it

	// Print the result to the console
	fmt.Println(res)
}

