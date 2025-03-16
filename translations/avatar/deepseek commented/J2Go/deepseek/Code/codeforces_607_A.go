package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	max := 0
	var n int
	var beacon [1000001]int
	var dp [1000001]int

	// Read the number of beacons
	scanner.Scan()
	n = toInt(scanner.Text())

	// Read the positions and strengths of the beacons
	for i := 0; i < n; i++ {
		scanner.Scan()
		a := toInt(scanner.Text())
		scanner.Scan()
		beacon[a] = toInt(scanner.Text())
	}

	// Check if the first beacon's strength is not zero and initialize dp[0] to 1
	if beacon[0] != 0 {
		dp[0] = 1
	}

	// Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
	for i := 1; i < 1000001; i++ {
		if beacon[i] != 0 && beacon[i] < i {
			dp[i] = dp[i-beacon[i]-1] + 1
		} else if beacon[i] != 0 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1]
		}
		if dp[i] > max {
			max = dp[i]
		}
	}

	// Print the result
	fmt.Println(n - max)
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

