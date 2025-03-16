package main

import (
	"bufio"
	"fmt"
	"os"
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

func parse(ss string) int {
	it := 0
	var parseHelper func() int
	parseHelper = func() int {
		c := ss[it]
		it++
		if '0' <= c && c <= '2' {
			return int(c - '0')
		}
		if c == '-' {
			return Not(parseHelper())
		}

		x := parseHelper()
		c = ss[it]
		it++
		y := parseHelper()
		it++
		if c == '*' {
			return And(x, y)
		}
		return Or(x, y)
	}
	return parseHelper()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		scanner.Scan()
		input := scanner.Text()
		if input == "." {
			break
		}
		cnt := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					ss := input
					ss = strings.ReplaceAll(ss, "P", fmt.Sprintf("%d", i))
					ss = strings.ReplaceAll(ss, "Q", fmt.Sprintf("%d", j))
					ss = strings.ReplaceAll(ss, "R", fmt.Sprintf("%d", k))
					if parse(ss) == 2 {
						cnt++
					}
				}
			}
		}
		fmt.Println(cnt)
	}
}

