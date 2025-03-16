
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of test cases from the console
	n, _ := strconv.Atoi(scanner.Text())

	// Define the maximum size of the array to avoid array out of bounds exception
	N := 100000 + 5

	// Initialize an array to store the count of each number
	cnt := make([]int, N)

	// Read the numbers one by one and update the count array accordingly
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(scanner.Text())
		cnt[num+10]++
	}

	// Calculate the result using the given formula
	res := 0
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i]
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2

	// Print the result to the console
	fmt.Println(res)
}

