
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Step 1: Input Reading
	// The Go code starts by reading the input value N and the array A of size N.
	N := readInt()
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		A[i] = readInt64()
	}

	// Step 2: Initialization
	// The dp array is initialized to a very large negative value to represent infinity,
	// except for dp[0][0][10] which is initialized to 0. This setup helps in finding the maximum value using dynamic programming.
	dp := make([][][]int64, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([][]int64, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int64, 20)
			for k := 0; k < 20; k++ {
				dp[i][j][k] = -1e18
			}
		}
	}
	dp[0][0][10] = 0

	// Step 3: Dynamic Programming Transition
	// The main loop iterates through each element of the array A and updates the dp array based on the previous states.
	// The transitions are carefully crafted to ensure the maximum value is computed considering two states: whether the current element is included or not.
	for i := 0; i < N; i++ {
		for j := 6; j <= 14; j++ {
			if dp[i][0][j]!= -1e18 {
				dp[i+1][1][j+1] = max(dp[i+1][1][j+1], dp[i][0][j]+A[i])
				dp[i+1][0][j-1] = max(dp[i+1][0][j-1], dp[i][0][j])
			}
			if dp[i][1][j]!= -1e18 {
				dp[i+1][0][j-1] = max(dp[i+1][0][j-1], dp[i][1][j])
			}
		}
	}

	// Step 4: Calculating the Result
	// After processing all elements, the code calculates the index V which is used to access the final states in the dp array.
	// It then outputs the maximum value between dp[N][0][V] and dp[N][1][V].
	V := 10 + N/2 - (N-N/2)
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]
	fmt.Println(max(T1, T2))
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int64
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func max(x, y int64) int64 {
	if x < y {
		return y
	}
	return x
}

