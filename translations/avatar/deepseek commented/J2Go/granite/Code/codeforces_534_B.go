

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 1: Read input values for v1, v2, t, and d.
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var v1, v2, t, d int
	sc.Scan()
	v1, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	v2, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	t, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	d, _ = strconv.Atoi(sc.Text())
	
	// Step 2: Initialize a 2D array dp with dimensions (t-1) x 1150, and fill it with a very small value (-1e17).
	dp := make([][]int64, t-1)
	for i := 0; i < t-1; i++ {
		dp[i] = make([]int64, 1150)
		for j := 0; j < 1150; j++ {
			dp[i][j] = -1e17
		}
	}
	
	// Step 3: Set the initial value of dp[0][v1] to v1.
	dp[0][v1] = v1
	
	// Step 4: Iterate through the time steps from 1 to t-2.
	sum := int64(0)
	for i := 1; i < t-1; i++ {
		// Step 5: For each time step, update the dp array based on the possible values of j (current position) and x (distance change).
		for j := 0; j < 1150; j++ {
			for x := 0; x <= d; x++ {
				if j+x < 1150 {
					dp[i][j] = max(dp[i][j], dp[i-1][j+x]+int64(j))
				}
			}
			for x := d; x >= 0; x-- {
				if j-x >= 0 {
					dp[i][j] = max(dp[i][j], dp[i-1][j-x]+int64(j))
				}
			}
		}
	}
	
	// Step 6: After updating the dp array, find the maximum value of dp[t-2][j] + v2 where the absolute difference between j and v2 is within the range d.
	ans := int64(math.MinInt64)
	for i := t - 2; i < t-1; i++ {
		for j := 0; j < 1150; j++ {
			if math.Abs(float64(j-v2)) <= float64(d) {
				ans = max(ans, dp[i][j]+int64(v2))
			}
		}
	}
	
	// Step 7: Print the result.
	fmt.Println(ans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

Translate the above Go code to C++ and end with comment "