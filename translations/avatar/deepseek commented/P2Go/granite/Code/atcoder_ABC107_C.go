
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

	var N, K int
	fmt.Fscanf(reader, "%d %d\n", &N, &K)

	lst := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &lst[i])
		if lst[i] == 0 {
			K--
		}
	}

	lstP := make([]int, 0)
	lstM := make([]int, 0)
	for i := 0; i < N; i++ {
		if lst[i] > 0 {
			lstP = append(lstP, lst[i])
		} else if lst[i] < 0 {
			lstM = append(lstM, lst[i])
		}
	}

	p, m := 0, 0
	x, y := 0, len(lstM)-1
	lastx, lasty := len(lstP), len(lstM)

	check := func(k int) int {
		ans := 1000000000
		for j := 0; j <= k; j++ {
			if j > lastx || k-j > lasty {
				continue
			}
			if j == 0 {
				p = 0
			} else {
				p = lstP[j-1]
			}
			if k-j == 0 {
				m = 0
			} else {
				m = lstM[lasty-(k-j)]
			}
			ans = min(ans, 2*p+abs(m), p+2*abs(m))
		}
		return ans
	}

	fmt.Println(check(K))
}

func min(a, b, c int) int {
	return min(min(a, b), c)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

