
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m, x int
	fmt.Fscanf(reader, "%d %d %d\n", &n, &m, &x)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			fmt.Fscanf(reader, "%d", &a[i][j])
		}
	}
	min := 100000000
	for i := 0; i < 1<<n; i++ {
		status := make([]int, n)
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 {
				status[j] = 1
			}
		}
		res := make([]int, m+1)
		for j := 0; j < n; j++ {
			if status[j] == 1 {
				for k := 0; k <= m; k++ {
					res[k] += a[j][k]
				}
			}
		}
		flag := true
		for j := 1; j <= m; j++ {
			if res[j] < x {
				flag = false
				break
			}
		}
		if flag {
			if res[0] < min {
				min = res[0]
			}
		}
	}
	if min == 100000000 {
		fmt.Println(-1)
	} else {
		fmt.Println(min)
	}
}
