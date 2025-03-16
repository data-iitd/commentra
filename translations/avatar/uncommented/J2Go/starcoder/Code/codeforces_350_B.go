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
	fmt.Scanf("%d", &n)
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &b[i])
	}
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}
	ss := ""
	ans := 0
	st := make([]bool, n+1)
	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			st[i] = true
			var sb strings.Builder
			x := b[i]
			var sss strings.Builder
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(" ")
			sb.WriteString(sss.String()[::-1])
			s := 1
			for!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1 {
				sss = strings.Builder{}
				sss.WriteString(strconv.Itoa(x))
				sb.WriteString(" ")
				sb.WriteString(sss.String()[::-1])
				st[x] = true
				x = b[x]
				s++
			}
			if s > ans {
				ans = s
				ss = sb.String()[::-1]
			}
		}
	}
	fmt.Println(ans)
	fmt.Println(ss)
}

