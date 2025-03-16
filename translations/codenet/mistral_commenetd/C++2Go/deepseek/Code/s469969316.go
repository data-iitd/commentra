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
	var c byte

	for it < len(ss) {
		c = ss[it]
		it++
		if '0' <= c && c <= '2' {
			return int(c - '0')
		}
		if c == '-' {
			return Not(parse(ss))
		}

		x := parse(ss)
		c = ss[it]
		it++
		y := parse(ss)
		it++
		if c == '*' {
			return And(x, y)
		}
		return Or(x, y)
	}
	return 0
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		input := scanner.Text()
		if input == "." {
			break
		}
		cnt := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a := []int{i, j, k}
					for idx, char := range input {
						if char == 'P' {
							input = strings.Replace(input, "P", fmt.Sprintf("%d", a[0]), 1)
						}
						if char == 'Q' {
							input = strings.Replace(input, "Q", fmt.Sprintf("%d", a[1]), 1)
						}
						if char == 'R' {
							input = strings.Replace(input, "R", fmt.Sprintf("%d", a[2]), 1)
						}
					}
					if parse(input) == 2 {
						cnt++
					}
				}
			}
		}
		fmt.Println(cnt)
	}
}

