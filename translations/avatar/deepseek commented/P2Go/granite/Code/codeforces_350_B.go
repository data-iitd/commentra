

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Fscan(bufio.NewReader(os.Stdin), &n)
	t := make([]int, n+1)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(bufio.NewReader(os.Stdin), &t[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Fscan(bufio.NewReader(os.Stdin), &a[i])
	}
	cnt := make([]int, n+1)
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
	for i := len(ans) - 1; i >= 0; i-- {
		fmt.Printf("%d ", ans[i])
	}
	fmt.Println()
}

