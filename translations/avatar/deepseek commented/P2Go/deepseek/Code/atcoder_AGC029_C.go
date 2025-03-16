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
	scanner.Scan()
	A := []int{}
	for _, numStr := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(numStr)
		A = append(A, num)
	}

	N := len(A)
	A = []int{A[0]}
	A = append(A, []int{j for i, j := range A[1:] if i >= j}...)

	type tuple struct {
		first  int
		second int
	}

	cut := func(array []tuple, index int) []tuple {
		if index < 1 {
			return []tuple{}
		}
		if index <= array[0].first {
			return []tuple{{index, array[0].second}}
		}
		for i := len(array) - 1; i > 0; i-- {
			if array[i-1].first < index {
				return append(array[:i], tuple{index, array[i].second})
			}
		}
		return array
	}

	isPossible := func(K int) bool {
		dp := []tuple{{A[0], 0}}
		for _, a := range A[1:] {
			if a <= dp[len(dp)-1].first {
				dp = cut(dp, a)
			} else {
				dp = append(dp, tuple{a, 0})
			}
			added := false
			for j := len(dp) - 1; j >= 0; j-- {
				if dp[j].second < K-1 {
					dp = cut(dp, dp[j].first-1)
					dp = append(dp, tuple{dp[j].first, dp[j].second + 1})
					if dp[len(dp)-1].first < a {
						dp = append(dp, tuple{a, 0})
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
		} else if isPossible((x+y)/2) {
			return bis(x, (x+y)/2)
		} else {
			return bis((x+y)/2, y)
		}
	}

	fmt.Println(bis(0, N))
}
