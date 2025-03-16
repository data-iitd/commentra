
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	t := make([]int, n+1)
	a := make([]int, n+1)
	cnt := make([]int, n+1)
	for i := 1; i <= n; i++ {
		t[i] = i
		a[i] = i
	}
	for i := 1; i <= n; i++ {
		cnt[i] = 0
	}
	for i := 1; i <= n; i++ {
		cnt[a[i]]++
	}
	ans := make([]int, 0)
	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := make([]int, 0)
			crt = append(crt, i)
			x := a[i]
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			if len(crt) > len(ans) {
				ans = crt
			}
		}
	}
	ans = ans[len(ans)-1:]
	for i := len(ans) - 1; i >= 0; i-- {
		ans[i] = ans[len(ans)-1-i]
	}
	fmt.Println(len(ans))
	fmt.Println(strings.Join(strings.Fields(fmt.Sprint(ans)), " "))
}

// 