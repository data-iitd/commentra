
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
	c := ss[it]
	if '0' <= c && c <= '2' {
		it++
		return c - '0'
	}
	if c == '-' {
		it++
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "." {
			break
		}
		count := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					ss := strings.Replace(line, "P", strconv.Itoa(i), -1)
					ss = strings.Replace(ss, "Q", strconv.Itoa(j), -1)
					ss = strings.Replace(ss, "R", strconv.Itoa(k), -1)
					if parse(ss) == 2 {
						count++
					}
				}
			}
		}
		fmt.Println(count)
	}
}

// Output the count