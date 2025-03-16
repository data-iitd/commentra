
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Step 1: Input Reading
	n, _ := strconv.Atoi(read(reader))
	c, _ := strconv.Atoi(read(reader))

	// Step 2: Vector Initialization
	x := make([]int, n+1)
	v := make([]int, n+1)

	// Step 3: Reading Positions and Values
	for i := 1; i < n+1; i++ {
		x[i], _ = strconv.Atoi(read(reader))
		v[i], _ = strconv.Atoi(read(reader))
	}

	// Step 4: Calculate Total Value Moving Left
	lefttotal := make([]int, n+1)
	maxlefttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
	}

	// Step 5: Calculate Maximum Value Left
	for i := 1; i < n+1; i++ {
		maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
	}

	// Step 6: Calculate Total Value Moving Right
	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	// Step 7: Calculate Maximum Value Right
	for i := 1; i < n+1; i++ {
		maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c-x[n+1-i]))
	}

	// Step 8: Calculate the Maximum Value
	ans := 0
	for i := 1; i < n+1; i++ {
		ans = max(ans, lefttotal[i]-x[i])
		ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i])
		ans = max(ans, righttotal[i]-(c-x[n+1-i]))
		ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])
	}

	// Step 9: Output the Result
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

