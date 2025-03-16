
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	t := make([]int, n+1)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &t[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a[i])
	}
	cnt := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cnt[a[i]]++
	}
	ans := make([]int, 0)
	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := make([]int, 0)
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
	for i, v := range ans {
		ans[i] = v
	}
	fmt.Println(len(ans))
	fmt.Println(strings.Join(strconv.FormatInt(int64(ans[i]), 10) for i := len(ans) - 1; i >= 0; i--))
}
