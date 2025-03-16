
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func nextInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())
	return x
}

func p(a, b int) int {
	if a < b {
		return a + b*n
	}
	return b + a*n
}

func f(from int) int {
	if b[from] {
		return -1
	}
	if d[from] != 0 {
		return d[from]
	}
	b[from] = true
	to := e1[from]
	max := 0
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	to = e2[from]
	if to != 0 {
		now := f(to)
		if now < 0 {
			return now
		}
		if now > max {
			max = now
		}
	}
	b[from] = false
	return d[from] = max + 1
}

func main() {
	n = nextInt()
	for i := 0; i < n; i++ {
		for j := 0; j < n-1; j++ {
			a[i][j] = nextInt() - 1
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n-2; j++ {
			from := p(i, a[i][j])
			to := p(i, a[i][j+1])
			if e1[from] == 0 {
				e1[from] = to
			} else if e2[from] == 0 {
				e2[from] = to
			} else {
				fmt.Println(-1)
				return
			}
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		from := p(i, a[i][0])
		now := f(from)
		if now < 0 {
			ans = -1
			break
		}
		if now > ans {
			ans = now
		}
	}
	fmt.Println(ans)
}

