package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&b[i])
		num[b[i]]++
	}

	var ss strings.Builder
	ans := 0
	st := make([]bool, n+1)

	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			st[i] = true
			var sb strings.Builder
			x := b[i]
			var sss strings.Builder
			sss.WriteString(fmt.Sprintf("%d", i))
			sb.WriteString(" " + reverseString(sss.String()))
			s := 1

			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sss.Reset()
				sss.WriteString(fmt.Sprintf("%d", x))
				sb.WriteString(" " + reverseString(sss.String()))
				st[x] = true
				x = b[x]
				s++
			}

			if s > ans {
				ans = s
				ss.Reset()
				ss.WriteString(reverseString(sb.String()))
			}
		}
	}

	fmt.Println(ans)
	fmt.Println(ss.String())
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// <END-OF-CODE>
