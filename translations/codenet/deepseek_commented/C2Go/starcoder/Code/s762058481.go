<<<<<<< HEAD

import (
	"fmt"
	"math"
=======
package main

import (
	"bufio"
	"fmt"
>>>>>>> 98c87cb78a (data updated)
	"os"
	"strconv"
	"strings"
)

// Function to return the smaller value between two integers
func chmin(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
<<<<<<< HEAD
	// Read the number of elements
	n, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	// Declare the dp array
	dp := make([]int, n)
	// Declare the h array
=======
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	dp := make([]int, n)
>>>>>>> 98c87cb78a (data updated)
	h := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = 10000
	}
<<<<<<< HEAD

	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
	}

	dp[0] = 0
	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = int(math.Abs(float64(h[1] - h[0])))
		} else {
			dp[i] = chmin(dp[i-1]+int(math.Abs(float64(h[i]-h[i-1]))), dp[i-2]+int(math.Abs(float64(h[i]-h[i-2]))))
=======
	fmt.Println("Enter the heights")
	for i := 0; i < n; i++ {
		h[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	dp[0] = 0
	for i := 1; i < n; i++ {
		if i == 1 {
			dp[1] = abs(h[1] - h[0])
		} else {
			dp[i] = chmin(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]))
>>>>>>> 98c87cb78a (data updated)
		}
	}
	fmt.Println(dp[n-1])
}

