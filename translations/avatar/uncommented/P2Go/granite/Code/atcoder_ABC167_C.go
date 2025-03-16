
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n, m, x int
	fmt.Fscanf(in, "%d %d %d\n", &n, &m, &x)
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m)
		fmt.Fscanf(in, "%s\n", &s)
		for j := 0; j < m; j++ {
			c[i][j], _ = strconv.Atoi(string(s[j]))
		}
	}
	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}
	l := make([][]int, 0)
	rem := make([]int, 0)
	ans := 0
	for i := 1; i <= n; i++ {
		for _, j := range combinations(pre, i) {
			l = append(l, j)
		}
		for i := 1; i <= m; i++ {
			for j, k := range l {
				ca := 0
				for _, ii := range k {
					ca += c[ii][i-1]
				}
				if ca < x {
					rem = append(rem, j)
				} else {
					// pass
				}
			}
			if len(rem) > 0 {
				for _, j := range rem {
					l = append(l[:j], l[j+1:]...)
				}
				rem = make([]int, 0)
			}
			if len(l) == 0 {
				fmt.Fprint(out, -1)
				goto END-OF-CODE
			}
		}
		for _, j := range l {
			ca := 0
			for _, ii := range j {
				ca += c[ii][0]
			}
			if ans == 0 {
				ans = ca
			} else {
				ans = min(ans, ca)
			}
		}
	}
	fmt.Fprint(out, ans)
END-OF-CODE:
	out.Flush()
}

func combinations(arr []int, r int) [][]int {
	var result [][]int
	var combination []int
	var backtrack func(int, int)
	backtrack = func(index, length int) {
		if length == r {
			result = append(result, append([]int{}, combination...))
			return
		}
		for i := index; i < len(arr); i++ {
			combination = append(combination, arr[i])
			backtrack(i+1, length+1)
			combination = combination[:len(combination)-1]
		}
	}
	backtrack(0, 0)
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}