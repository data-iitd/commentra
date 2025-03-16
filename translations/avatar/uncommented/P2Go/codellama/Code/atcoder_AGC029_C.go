package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[i])
	}
	A = append([]int{A[0]}, func() []int {
		res := make([]int, 0)
		for i := 1; i < N; i++ {
			if A[i] <= A[i-1] {
				continue
			}
			res = append(res, A[i])
		}
		return res
	}())
	N = len(A)
	cut := func(array [][]int, index int) [][]int {
		if index < 1 {
			return [][]int{}
		}
		if index <= array[0][0] {
			return [][]int{{index, array[0][1]}}
		}
		for i := len(array) - 1; i > 0; i-- {
			if array[i-1][0] < index {
				return array[:i]
			}
		}
		return [][]int{}
	}
	is_possible := func(K int) bool {
		dp := [][]int{{A[0], 0}}
		for _, a := range A[1:] {
			if a <= dp[len(dp)-1][0] {
				dp = cut(dp, a)
			} else {
				dp = append(dp, []int{a, 0})
			}
			is_added := false
			for j := len(dp) - 1; j >= 0; j-- {
				if dp[j][1] < K-1 {
					dp = cut(dp, dp[j][0]-1)
					dp = append(dp, []int{dp[j][0], dp[j][1] + 1})
					if dp[len(dp)-1][0] < a {
						dp = append(dp, []int{a, 0})
					}
					is_added = true
					break
				}
			}
			if !is_added {
				return false
			}
		}
		return true
	}
	bis := func(x, y int) int {
		if y == x+1 {
			return y
		}
		if is_possible((x + y) / 2) {
			return bis(x, (x+y)/2)
		} else {
			return bis((x+y)/2, y)
		}
	}
	fmt.Println(bis(0, N))
}

