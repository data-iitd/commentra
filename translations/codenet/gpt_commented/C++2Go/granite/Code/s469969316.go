
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to compute the NOT operation
func Not(x int) int {
	return 2 - x
}

// Function to compute the AND operation
func And(x, y int) int {
	if x*y == 0 {
		return 0
	}
	if x == 2 && y == 2 {
		return 2
	}
	return 1
}

// Function to compute the OR operation
func Or(x, y int) int {
	if x == 2 || y == 2 {
		return 2
	}
	if x == 1 || y == 1 {
		return 1
	}
	return 0
}

// Recursive function to parse the expression and evaluate it
func parse(ss string, it *int) int {
	c := ss[*it]
	*it++
	if '0' <= c && c <= '2' {
		return c - '0'
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

// Main function to read input and evaluate expressions
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
					ss := input
					for _, c := range []string{"P", "Q", "R"} {
						ss = strings.ReplaceAll(ss, c, strconv.Itoa(i))
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
