package main

import (
	"fmt"
	"strings"
)

var (
	input string
	ss    string
	a     [3]int
	it    int
	cnt   int
)

func Not(x int) int {
	return 2 - x
}

func And(x, y int) int {
	if x*y == 0 {
		return 0
	}
	if x == 2 && y == 2 {
		return 2
	}
	return 1
}

func Or(x, y int) int {
	if x == 2 || y == 2 {
		return 2
	}
	if x == 1 || y == 1 {
		return 1
	}
	return 0
}

func parse() int {
	c := ss[it]
	it++
	if '0' <= c && c <= '2' {
		return int(c - '0')
	}
	if c == '-' {
		return Not(parse())
	}

	x := parse()
	c = ss[it]
	it++
	y := parse()
	it++
	return c == '*' ? And(x, y) : Or(x, y)
}

func main() {
	for {
		fmt.Scan(&input)
		if input == "." {
			break
		}
		rep(i, 3)
		a[i] = i
		cnt = 0
		rep(i, 3)
		rep(j, 3)
		rep(k, 3) {
			a[0] = i
			a[1] = j
			a[2] = k
			ss = input
			for i, c := range ss {
				if c == 'P' {
					ss = strings.Replace(ss, "P", string(a[0]+'0'), 1)
				}
				if c == 'Q' {
					ss = strings.Replace(ss, "Q", string(a[1]+'0'), 1)
				}
				if c == 'R' {
					ss = strings.Replace(ss, "R", string(a[2]+'0'), 1)
				}
			}
			it = 0
			if parse() == 2 {
				cnt++
			}
		}
		fmt.Println(cnt)
	}
}

