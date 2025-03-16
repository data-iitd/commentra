package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Step 1: Define the Not function
func Not(x int) int {
	return 2 - x
}

// Step 2: Define the And function
func And(x, y int) int {
	if x*y == 0 {
		return 0
	}
	if x == 2 && y == 2 {
		return 2
	}
	return 1
}

// Step 3: Define the Or function
func Or(x, y int) int {
	if x == 2 || y == 2 {
		return 2
	}
	if x == 1 || y == 1 {
		return 1
	}
	return 0
}

// Step 4: Implement the parse function
func parse(ss string) int {
	it := 0
	for it < len(ss) {
		c := ss[it]
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

// Step 5: Implement the main function
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
					ss := strings.ReplaceAll(input, "P", fmt.Sprintf("%d", i))
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

// Step 6: Output the count
