package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {
	var input string
	fmt.Scanln(&input)
	A := make([]int, 0)
	for _, s := range split(input) {
		A = append(A, toInt(s))
	}
	A = append([]int{A[0]}, filter(A)...)
	N := len(A)

	result := bis(0, N)
	fmt.Println(result)
}

func split(s string) []string {
	return strings.Fields(s)
}

func toInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func filter(A []int) []int {
	result := []int{}
	for i := 1; i < len(A); i++ {
		if A[i-1] >= A[i] {
			result = append(result, A[i])
		}
	}
	return result
}

func cut(array [][2]int, index int) [][2]int {
	if index < 1 {
		return [][2]int{}
	}
	if index <= array[0][0] {
		return [][2]int{{index, array[0][1]}}
	}
	for i := len(array) - 1; i > 0; i-- {
		if array[i-1][0] < index {
			return append(array[:i], [2]int{index, array[i][1]})
		}
	}
	return array
}

func isPossible(K int, A []int) bool {
	dp := [][2]int{{A[0], 0}}
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
				dp = append(dp, [2]int{dp[j][0], dp[j][1] + 1})
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
	} else if isPossible((x+y)/2, A) {
		return bis(x, (x+y)/2, A)
	} else {
		return bis((x+y)/2, y, A)
	}
}

// <END-OF-CODE>
