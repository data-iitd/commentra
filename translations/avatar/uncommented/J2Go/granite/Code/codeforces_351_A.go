
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	input := make([]float64, 2*n)
	line, _ := reader.ReadString('\n')
	tokens := strings.Split(line, " ")
	nonInt := 0
	sumBefore := 0.0
	sum := 0.0
	for i := 0; i < 2*n; i++ {
		num, _ := strconv.ParseFloat(tokens[i], 64)
		sumBefore += num
		if num!= float64(int(num)) {
			nonInt++
		}
		sum += float64(int(num))
		input[i] = num
	}
	maxSum := float64(min(n, nonInt)) + sum
	minSum := float64(max(0, nonInt-n)) + sum
	var ans float64
	if minSum > sumBefore {
		ans = minSum - sumBefore
	} else if maxSum < sumBefore {
		ans = sumBefore - maxSum
	} else {
		x := sumBefore - float64(int(sumBefore))
		ans = min(1-x, x)
	}
	fmt.Printf("%.3f\n", ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

