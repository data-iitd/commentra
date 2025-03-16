
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
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the value of X")
	X, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString()), 10, 64)
	x := make([]int, N)
	xsum := make([]int, N+1)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		xsum[i+1] = xsum[i] + x[i]
	}
	ans := X * N + 5 * xsum[N]
	for i := 1; i < N; i++ {
		cost := X * i + 5*(xsum[N]-xsum[N-i])
		for j := 5; k := N-i; k >= 0; j += 2 {
			if cost > ans {
				break
			}
			cost += j * (xsum[k] - xsum[max(k-i, 0)])
		}
		ans = min(ans, cost)
	}
	fmt.Println(ans + N * X)
}

