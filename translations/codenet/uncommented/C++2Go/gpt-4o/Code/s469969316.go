package main

import (
	"fmt"
	"strings"
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

func parse(ss string, it *int) int {
	c := ss[*it]
	*it++
	if c >= '0' && c <= '2' {
		return int(c - '0')
	}
	if c == '-' {
		return Not(parse(ss, it))
	}

	x := parse(ss, it)
	c = ss[*it]
	*it++
	y := parse(ss, it)
	*it++
	if c == '*' {
		return And(x, y)
	}
	return Or(x, y)
}

func main() {
	var input string
	for {
		fmt.Scan(&input)
		if input == "." {
			break
		}
		cnt := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a := []int{i, j, k}
					ss := input
					for _, c := range ss {
						if c == 'P' {
							ss = strings.Replace(ss, string(c), fmt.Sprintf("%d", a[0]), 1)
						} else if c == 'Q' {
							ss = strings.Replace(ss, string(c), fmt.Sprintf("%d", a[1]), 1)
						} else if c == 'R' {
							ss = strings.Replace(ss, string(c), fmt.Sprintf("%d", a[2]), 1)
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

// <END-OF-CODE>
