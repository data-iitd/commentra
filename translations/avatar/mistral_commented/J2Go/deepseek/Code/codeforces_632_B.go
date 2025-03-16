package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := toInt(scanner.Text())
	a := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i] = toInt(scanner.Text())
	}

	scanner.Scan()
	s := scanner.Text()
	sum := 0

	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += a[i]
		}
	}

	ans := sum
	sum1 := sum

	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		ans = max(ans, sum1)
	}

	sum1 = sum

	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		ans = max(ans, sum1)
	}

	fmt.Println(ans)
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

