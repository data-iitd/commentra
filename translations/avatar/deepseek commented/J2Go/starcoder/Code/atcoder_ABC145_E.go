
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of dishes: ")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the time limit for eating dishes: ")
	T, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

	// Initialize the array to store dishes with their time and value
	AB := make([][]int, N)
	for i := 0; i < N; i++ {
		fmt.Println("Enter the time for dish", i+1, ": ")
		time, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		fmt.Println("Enter the value for dish", i+1, ": ")
		value, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		AB[i] = []int{time, value}
	}

	// Sort the dishes based on their eating time
	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	// Initialize the DP table with dimensions (N+1) x 6001
	dp := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, 6001)
	}

	// Fill the DP table
	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			// Inherit the maximum value from the previous dish
			dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat])

			// Get the time and value of the current dish
			time := AB[i-1][0]
			value := AB[i-1][1]

			// If the dish can be eaten after the given time, update the DP table
			if 0 <= timeAfterEat-time && timeAfterEat-time < T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
			}
		}
	}

	// Print the maximum value that can be obtained within the time limit
	fmt.Println(max(dp[N]...))
}

func max(nums...int) int {
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

