
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "\n")
	A := make([]int, 0)
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		for _, x := range bytes.Split(line, []byte{' '}) {
			if len(x) == 0 {
				continue
			}
			y, _ := strconv.Atoi(string(x))
			A = append(A, y)
		}
	}
	N := len(A)
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
		for i := 1; i < N; i++ {
			if A[i] <= dp[len(dp)-1][0] {
				dp = cut(dp, A[i])
			} else {
				dp = append(dp, [2]int{A[i], 0})
			}
			isAdded := false
			for j := len(dp) - 1; j >= 0; j-- {
				if dp[j][1] < K-1 {
					dp = append(cut(dp, dp[j][0]-1), [2]int{dp[j][0], dp[j][1]+1}...)
					if dp[len(dp)-1][0] < A[i] {
						dp = append(dp, [2]int{A[i], 0})
					}
					isAdded = true
					break
				}
			}
			if!isAdded {
				return false
			}
		}
		return true
	}
	bis := func(x int, y int) int {
		if y == x+1 {
			return y
		}
		if isPossible((x+y)/2) {
			return bis(x, (x+y)/2)
		} else {
			return bis((x+y)/2, y)
		}
	}
	fmt.Println(bis(0, N))
}

