package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner = bufio.NewScanner(os.Stdin)

func main() {
	scanner.Scan()
	n := 0
	fmt.Sscanf(scanner.Text(), "%d", &n)

	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	for i := 1; i <= n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d", &a[i], &b[i])
	}

	ss := ""
	ans := 0
	st := make([]bool, n+1)

	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			st[i] = true
			sb := ""
			x := b[i]
			sss := fmt.Sprintf("%d", i)
			sb += " " + reverseString(sss)
			s := 1

			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sss = fmt.Sprintf("%d", x)
				sb += " " + reverseString(sss)
				st[x] = true
				x = b[x]
				s++
			}

			if s > ans {
				ans = s
				ss = reverseString(sb)
			}
		}
	}

	fmt.Println(ans)
	fmt.Println(ss)
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

