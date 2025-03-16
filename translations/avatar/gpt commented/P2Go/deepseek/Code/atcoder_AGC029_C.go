package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()
	A := []int{}
	for _, numStr := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(numStr)
		A = append(A, num)
	}

	N := len(A)
	A = append([]int{A[0]}, []int{A[1]}...)

	cut := func(array [][2]int, index int) [][2]int {
		if index < 1 {
			return [][2]int{}
		}
		if index <= array[0][0] {
			return [][2]int{{index, array[0][1]}}
		}
		for i := len(array) - 1; i > 0; i-- {
			if array[i-1][0] < index {
				return append(array[:i], [][2]int{{index, array[i][1]}}...)
			}
		}
		return array
	}

	isPossible := func(K int) bool {
		dp := [][2]int{{A[0], 0}}
		for _, a := range A[1:] {
			if a <= dp[len(dp)-1][0] {
				dp = cut(dp, a)
			} else {
				dp = append(dp, [2]int{a, 0})
			}
			added := false
			for j := len(dp) - 1; j >= 0; j-- {
				if dp[j][1] < K-1 {
					dp = cut(dp, dp[j][0]-1)
					dp = append(dp, [2]int{dp[j][0], dp[j][1] + 1})
					if dp[len(dp)-1][0] < a {
						dp = append(dp, [2]int{a, 0})
					}
					added = true
					break
				}
			}
			if !added {
				return false
			}
		}
		return true
	}

	bis := func(x, y int) int {
		if y == x+1 {
			return y
		}
		if isPossible((x+y)/2) {
			return bis(x, (x+y)/2)
		}
		return bis((x+y)/2, y)
	}

	fmt.Println(bis(0, N))
}
