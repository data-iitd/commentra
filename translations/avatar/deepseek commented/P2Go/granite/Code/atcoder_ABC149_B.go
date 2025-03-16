

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	cookies := make([]int, 3)
	for i, s := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(s)
		cookies[i] = num
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)
	fmt.Println(takahashi, cookies[1]-abs(leftOver))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

