
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func Not(x int) int { // Function to calculate NOT of a binary number
	return 2 - x
}

func And(x, y int) int { // Function to calculate AND of two binary numbers
	if x*y == 0 {
		return 0
	}
	if x == 2 && y == 2 {
		return 2
	}
	return 1
}

func Or(x, y int) int { // Function to calculate OR of two binary numbers
	if x == 2 || y == 2 {
		return 2
	}
	if x == 1 || y == 1 {
		return 1
	}
	return 0
}

func parse(ss string) int { // Function to parse the input string and calculate the logical expression
	it := 0
	c := ss[it]
	it++
	if '0' <= c && c <= '2' {
		return c - '0'
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

func main() { // Main function
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() { // Read input until end of file is reached
		line := scanner.Text()
		if line == "." {
			break
		}
		a := []int{0, 1, 2}
		cnt := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					a[0] = i
					a[1] = j
					a[2] = k
					ss := line
					for i, c := range ss {
						if c == 'P' {
							ss = ss[:i] + strconv.Itoa(a[0]) + ss[i+1:]
						}
						if c == 'Q' {
							ss = ss[:i] + strconv.Itoa(a[1]) + ss[i+1:]
						}
						if c == 'R' {
							ss = ss[:i] + strconv.Itoa(a[2]) + ss[i+1:]
						}
					}
					it := 0
					if parse(ss) == 2 {
						cnt++
					}
				}
			}
		}
		fmt.Println(cnt)
	}
}

