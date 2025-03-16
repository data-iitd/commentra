package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read input from stdin
func readInput(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

// Function to read input from stdin and convert it to an integer
func readInt(reader *bufio.Reader) int {
	input := readInput(reader)
	i, _ := strconv.Atoi(input)
	return i
}

// Function to read input from stdin and convert it to a float
func readFloat(reader *bufio.Reader) float64 {
	input := readInput(reader)
	f, _ := strconv.ParseFloat(input, 64)
	return f
}

// Function to read input from stdin and convert it to a rune
func readRune(reader *bufio.Reader) rune {
	input := readInput(reader)
	r, _ := strconv.ParseRune(input)
	return r
}

// Function to read input from stdin and convert it to a string
func readString(reader *bufio.Reader) string {
	input := readInput(reader)
	return input
}

// Function to read input from stdin and convert it to a boolean
func readBool(reader *bufio.Reader) bool {
	input := readInput(reader)
	b, _ := strconv.ParseBool(input)
	return b
}

// Main function
func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of activities N and the time limit T from stdin
	N := readInt(reader)
	T := readInt(reader)

	// Initialize a 2D array AB to store the start time and value of each activity
	AB := make([][]int, N)

	// Read the start time and value of each activity from stdin and store it in the AB array
	for i := 0; i < N; i++ {
		AB[i] = make([]int, 2)
		AB[i][0] = readInt(reader) // Read the start time of activity i
		AB[i][1] = readInt(reader) // Read the value of activity i
	}

	// Sort the AB array based on the start time of each activity
	sort.Slice(AB, func(i, j int) bool {
		return AB[i][0] < AB[j][0]
	})

	// Initialize a 2D array dp to store the maximum value that can be obtained up to a certain time after eating an activity
	dp := make([][]int, N + 1)
	for i := 0; i <= N; i++ {
		dp[i] = make([]int, 6001)
	}

	// For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
	for i := 1; i <= N; i++ {
		for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
			// Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
			dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat])

			// If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
			time := AB[i - 1][0]
			value := AB[i - 1][1]
			if timeAfterEat >= time && timeAfterEat < time + T {
				dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value)
			}
		}
	}

	// Print the maximum value that can be obtained after eating all the activities
	fmt.Println(max(dp[N]...))
}

// Function to return the maximum value in a given array
func max(nums...int) int {
	max := nums[0]
	for _, num := range nums {
		if num > max {
			max = num
		}
	}
	return max
}

