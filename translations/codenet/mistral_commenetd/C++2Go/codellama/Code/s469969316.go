package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	for {
		fmt.Scan(&input)
		if input == "." {
			break
		}
		a := [3]int{0, 1, 2}
		cnt := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a[0] = i
					a[1] = j
					a[2] = k
					ss := input
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
					it := 0
					if parse(ss, &it) == 2 {
						cnt++
					}
				}
			}
		}
		fmt.Println(cnt)
	}
}

func parse(ss string, it *int) int {
	c := ss[*it]
	if c >= '0' && c <= '2' {
		*it++
		return int(c - '0')
	}
	if c == '-' {
		*it++
		return Not(parse(ss, it))
	}

	x := parse(ss, it)
	c = ss[*it]
	*it++
	y := parse(ss, it)
	*it++
	return c == '*' ? And(x, y) : Or(x, y)
}

func Not(x int) int {
	if x == 0 {
		return 2
	}
	return 1
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

