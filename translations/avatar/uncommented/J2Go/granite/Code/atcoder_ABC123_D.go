
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var x [3]int
	var max int
	for i := 0; i < 3; i++ {
		tmp, _ := reader.ReadString('\n')
		x[i], _ = strconv.Atoi(strings.TrimSpace(tmp))
		if x[i] > max {
			max = x[i]
		}
	}
	k, _ := reader.ReadString('\n')
	k, _ = strconv.Atoi(strings.TrimSpace(k))
	a := make([][]int64, 3)
	for i := 0; i < 3; i++ {
		a[i] = make([]int64, x[i])
		for j := 0; j < x[i]; j++ {
			tmp, _ := reader.ReadString('\n')
			a[i][j], _ = strconv.ParseInt(strings.TrimSpace(tmp), 10, 64)
		}
		sort.Slice(a[i], func(i, j int) bool {
			return a[i][j] > a[j][i]
		})
	}
	ans := make([]int64, 0)
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][i] + a[1][j] + a[2][m]
					ans = append(ans, tmp)
				}
			}
		}
	}
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] > ans[j]
	})
	for i := 0; i < k; i++ {
		fmt.Println(ans[i])
	}
}
