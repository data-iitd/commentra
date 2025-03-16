package main

import (
	"fmt"
	"strconv"
	"strings"
)

func cut(array [][2]int, index int) [][2]int {
	if index < 1 {
		return [][2]int{}
	}
	if index <= array[0][0] {
		return [][2]int{ {index, array[0][1]} }
	}
	for i := len(array) - 1; i > 0; i-- {
		if array[i-1][0] < index {
			return append(array[:i], [2]int{index, array[i][1]})
		}
	}
	return array
}

func isPossible(K int, A []int) bool {
	dp := [][2]int{ {A[0], 0} }
	for _, a := range A[1:] {
		if a <= dp[len(dp)-1][0] {
			dp = cut(dp, a)
		} else {
			dp = append(dp, [2]int{a, 0})
		}
		isAdded := false
		for j := len(dp) - 1; j >= 0; j-- {
			if dp[j][1] < K-1 {
				dp = cut(dp, dp[j][0]-1)
				dp = append(dp[:j+1], [2]int{dp[j][0], dp[j][1] + 1})
				if dp[len(dp)-1][0] < a {
					dp = append(dp, [2]int{a, 0})
				}
				isAdded = true
				break
			}
		}
		if !isAdded {
			return false
		}
	}
	return true
}

func bis(x, y int, A []int) int {
	if y == x+1 {
		return y
	}
	mid := (x + y) / 2
	if isPossible(mid, A) {
		return bis(x, mid, A)
	} else {
		return bis(mid, y, A)
	}
}

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, " ")
	A := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		A = append(A, num)
	}
	N := len(A)
	A = append([]int{A[0]}, []int{j for i, j := range zip(A, A[1:])}...)
	result := bis(0, N, A)
	fmt.Println(result)
}
