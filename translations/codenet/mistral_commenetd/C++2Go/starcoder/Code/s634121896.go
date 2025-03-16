<<<<<<< HEAD

=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of test cases (if any) or the main input
	var n int
	fmt.Scanf("%d\n", &n)
	// Initialize the vector to store the numbers
	nums := make([]int, n)
	// Initialize variables to keep track of the last number and the previous index of the last number
	last := 0
	for i := 0; i < n; i++ {
		// Read the numbers from the input
		fmt.Scanf("%d\n", &nums[i])
		// Update the last variable and the map to keep track of the previous index of the last number
		last = nums[i]
	}
	// Initialize a vector to store the prefix sum of the number of ways to reach each index
	dp := make([]int, n+1)
	// Set the initial value of the prefix sum at index 0
	dp[0] = 1
	// Initialize two maps to keep track of the previous index of each number and the number of ways to reach the previous index
	kek := make(map[int]int)
	prev := make(map[int]int)
	// Iterate through the numbers from 1 to n
	for i := 1; i <= n; i++ {
		// Calculate the prefix sum at the current index by adding the number of ways to reach the previous index (if the previous number is not the same as the current number) and updating the maps
		dp[i] = dp[i-1] + (prev[nums[i-1]]!= i-1)
		dp[i] %= MOD
		// Update the maps
		kek[nums[i-1]] = dp[i]
		prev[nums[i-1]] = i
	}
	// Output the result
	fmt.Printf("%d\n", dp[n])
}

