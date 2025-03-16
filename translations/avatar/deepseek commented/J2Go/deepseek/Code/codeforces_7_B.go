package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	t := toInt(scanner.Text())
	scanner.Scan()
	m := toInt(scanner.Text())
	memory := make([]int, m)
	allocIdx := 0

	for j := 0; j < t; j++ {
		scanner.Scan()
		command := scanner.Text()
		switch command {
		case "alloc":
			scanner.Scan()
			n := toInt(scanner.Text())
			len := 0
			canAlloc := false

			for i := 0; i < m; i++ {
				if memory[i] == 0 {
					len++
				} else {
					len = 0
				}

				if len == n {
					canAlloc = true
					len = i - n + 1
					break
				}
			}

			if canAlloc {
				allocIdx++
				for i := len; i < len+n; i++ {
					memory[i] = allocIdx
				}
				fmt.Println(allocIdx)
			} else {
				fmt.Println("NULL")
			}

		case "erase":
			scanner.Scan()
			x := toInt(scanner.Text())
			if x <= 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				continue
			}
			hasErased := false

			for i := 0; i < m; i++ {
				if memory[i] == x {
					memory[i] = 0
					hasErased = true
				}
			}

			if !hasErased {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			}

		case "defragment":
			d := 0
			for i := 0; i < m; i++ {
				if memory[i] == 0 {
					d++
				} else {
					memory[i-d] = memory[i]
				}
			}
			for i := m - d; i < m; i++ {
				memory[i] = 0
			}

		default:
			fmt.Println("h")
		}
	}
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

