package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	for {
		var n, m int
		_, err := fmt.Scanf("%d %d\n", &n, &m)
		if err!= nil {
			break
		}
		if n == 0 {
			break
		}
		here := make([]int, 100001)
		dp1 := make([]int, 100001)
		dp2 := make([]int, 100001)
		for i := 0; i < 100001; i++ {
			here[i] = 0
			dp1[i] = 0
			dp2[i] = 0
		}
		dpflg := false
		for i := 0; i < m; i++ {
			var a int
			_, err := fmt.Scanf("%d\n", &a)
			if err!= nil {
				break
			}
			if a == 0 {
				dpflg = true
			}
			here[a] = 1
		}
		maxi1 := 0
		maxi2 := 0
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp1[i] = dp1[i-1] + 1
			}
			maxi1 = max(maxi1, dp1[i])
		}
		for i := 1; i <= n; i++ {
			if here[i] == 1 {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = dp1[i-1] + 1
			}
			maxi2 = max(maxi2, dp2[i])
		}
		if!dpflg {
			fmt.Printf("%d\n", maxi1)
		} else {
			fmt.Printf("%d\n", maxi2)
		}
	}
}

