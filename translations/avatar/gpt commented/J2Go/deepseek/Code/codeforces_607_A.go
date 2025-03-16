package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)
	
	// Initialize a variable to keep track of the maximum number of beacons
	max := 0
	
	// Read the number of beacons
	sc.Scan()
	n, _ := fmt.Sscan(sc.Text(), &n)
	
	// Create an array to store the positions of the beacons
	beacon := make([]int, 1000001)
	
	// Create a dynamic programming array to store the maximum beacons that can be placed
	dp := make([]int, 1000001)
	
	// Read the beacon positions and their corresponding values
	for i := 0; i < n; i++ {
		var a int
		sc.Scan()
		fmt.Sscan(sc.Text(), &a)
		sc.Scan()
		beacon[a] = a
	}
	
	// Initialize the dp array for the first position if there is a beacon
	if beacon[0] != 0 {
		dp[0] = 1
	}
	
	// Iterate through all possible positions to calculate the maximum beacons that can be placed
	for i := 1; i < 1000001; i++ {
		// If there is a beacon at position i and its value is less than i
		if beacon[i] != 0 && beacon[i] < i {
			// Update the dp array based on the previous values
			dp[i] = dp[i - beacon[i] - 1] + 1
		} else if beacon[i] != 0 { // If there is a beacon at position i but its value is greater than or equal to i
			dp[i] = 1 // Only this beacon can be placed
		} else { // If there is no beacon at position i
			dp[i] = dp[i - 1] // Carry forward the previous maximum
		}
		// Update the maximum number of beacons found so far
		if dp[i] > max {
			max = dp[i]
		}
	}
	
	// Output the minimum number of beacons that need to be removed
	fmt.Println(n - max)
}

