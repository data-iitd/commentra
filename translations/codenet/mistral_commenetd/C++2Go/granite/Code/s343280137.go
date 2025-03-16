
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, c int64
	fmt.Fscanf(reader, "%d %d\n", &n, &c)

	x := make([]int64, n+1)
	v := make([]int64, n+1)
	for i := 1; i < n+1; i++ {
		fmt.Fscanf(reader, "%d %d\n", &x[i], &v[i])
	}

	leftTotal := make([]int64, n+1)
	maxLeftTotal := make([]int64, n+1)
	for i := 1; i < n+1; i++ {
		leftTotal[i] = leftTotal[i-1] + v[i]
		maxLeftTotal[i] = int64(max(int(maxLeftTotal[i-1]), int(leftTotal[i]-x[i])))
	}

	rightTotal := make([]int64, n+1)
	maxRightTotal := make([]int64, n+1)
	for i := 1; i < n+1; i++ {
		rightTotal[i] = rightTotal[i-1] + v[n-i+1]
		maxRightTotal[i] = int64(max(int(maxRightTotal[i-1]), int(rightTotal[i]-(c-x[n-i+1]))))
	}

	ans := int64(0)
	for i := 1; i < n+1; i++ {
		ans = int64(max(int(ans), int(leftTotal[i]-x[i])))
		ans = int64(max(int(ans), int(leftTotal[i]-2*x[i]+maxRightTotal[n-i])))
		ans = int64(max(int(ans), int(rightTotal[i]-(c-x[n-i+1]))))
		ans = int64(max(int(ans), int(rightTotal[i]-2*(c-x[n-i+1])+maxLeftTotal[n-i])))
	}

	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

