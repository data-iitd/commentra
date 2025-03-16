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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	t := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(reader, &t[i])
	}

	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	ans := []int{}
	cnt := make([]int, n+1)

	for _, i := range a {
		cnt[i]++
	}

	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := []int{}
			x := a[i]
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			if len(crt) > len(ans) {
				ans = append([]int{}, crt...)
			}
		}
	}

	for i := 0; i < len(ans)/2; i++ {
		ans[i], ans[len(ans)-1-i] = ans[len(ans)-1-i], ans[i]
	}

	fmt.Fprintln(writer, len(ans))
	fmt.Fprintln(writer, strings.Trim(fmt.Sprint(ans), "[]"))
}

