
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
	fmt.Fscanln(reader)
	A := make([]int, 0)
	for _, s := range strings.Split(strings.TrimSpace(reader.ReadString()), " ") {
		A = append(A, strconv.Atoi(s))
	}
	A = append(A, 0)
	for i := 0; i < len(A)-1; i++ {
		if A[i] < A[i+1] {
			A[i+1] = A[i]
		}
	}
	A = A[:len(A)-1]
	N := len(A)
	dp := make([][]int, 0)
	dp = append(dp, []int{A[0], 0})
	for _, a := range A[1:] {
		if a <= dp[len(dp)-1][0] {
			dp = dp[:len(dp)-1]
		} else {
			dp = append(dp, []int{a, 0})
		}
		isAdded := false
		for j := len(dp) - 1; j >= 0; j-- {
			if dp[j][1] < K-1 {
				dp = dp[:j] + []int{dp[j][0] - 1, dp[j][1] + 1}
				if dp[len(dp)-1][0] < a {
					dp = append(dp, []int{a, 0})
				}
				isAdded = true
				break
			}
		}
		if!isAdded {
			break
	}
	fmt.Println(dp[len(dp)-1][1])
}

