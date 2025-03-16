
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
	fmt.Println("Enter the number of points N and the target value X")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, "\r", "", -1)
	input = strings.Replace(input, " ", "", -1)
	input_arr := strings.Split(input, ",")
	N, _ := strconv.Atoi(input_arr[0])
	X, _ := strconv.Atoi(input_arr[1])

	x := make([]int, N)
	xsum := make([]int, N+1)
	for i := 0; i < N; i++ {
		fmt.Println("Enter the position of the point", i+1)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		input = strings.Replace(input, "\n", "", -1)
		input = strings.Replace(input, "\r", "", -1)
		input = strings.Replace(input, " ", "", -1)
		x[i], _ = strconv.Atoi(input)
		xsum[i+1] = xsum[i] + x[i]
	}

	ans := X * N + 5 * xsum[N]
	for i := 1; i < N; i++ {
		cost := X * i + 5 * (xsum[N] - xsum[N-i])
		for j := 5; j <= 2*i; j += 2 {
			if cost > ans {
				break
			}
			cost += j * (xsum[N-i] - xsum[max(N-i-i, 0)])
		}
		ans = min(ans, cost)
	}
	fmt.Println(ans + N*X)
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

