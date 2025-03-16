package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of beacons
	n, _ := strconv.Atoi(readLine(reader))

	// Create an array to store the positions of the beacons
	beacon := make([]int, 1000001)

	// Create a dynamic programming array to store the maximum beacons that can be placed
	dp := make([]int, 1000001)

	// Read the beacon positions and their corresponding values
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(readLine(reader)) // Read the position of the beacon
		beacon[a], _ = strconv.Atoi(readLine(reader)) // Read the value associated with the beacon at that position
	}

	// Initialize the dp array for the first position if there is a beacon
	if beacon[0]!= 0 {
		dp[0] = 1
	}

	// Iterate through all possible positions to calculate the maximum beacons that can be placed
	for i := 1; i < 1000001; i++ {
		// If there is a beacon at position i and its value is less than i
		if beacon[i]!= 0 && beacon[i] < i {
			// Update the dp array based on the previous values
			dp[i] = dp[i-beacon[i]-1] + 1
		}
		// If there is a beacon at position i but its value is greater than or equal to i
		else if beacon[i]!= 0 {
			dp[i] = 1 // Only this beacon can be placed
		}
		// If there is no beacon at position i
		else {
			dp[i] = dp[i-1] // Carry forward the previous maximum
		}
	}

	// Output the minimum number of beacons that need to be removed
	fmt.Println(n - dp[1000000])
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

