package main

import (
	"fmt"
)

func main() {
	var t, m int
	fmt.Scan(&t, &m)
	memory := make([]int, m)
	allocIdx := 0

	for j := 0; j < t; j++ {
		var command string
		fmt.Scan(&command)

		switch command {
		case "alloc":
			var n int
			fmt.Scan(&n)
			len := 0
			canAlloc := false
			startIdx := 0

			for i := 0; i < m; i++ {
				if memory[i] == 0 {
					len++
				} else {
					len = 0
				}
				if len == n {
					canAlloc = true
					startIdx = i - n + 1
					break
				}
			}

			if canAlloc {
				allocIdx++
				for i := startIdx; i < startIdx+n; i++ {
					memory[i] = allocIdx
				}
				fmt.Println(allocIdx)
			} else {
				fmt.Println("NULL")
			}

		case "erase":
			var x int
			fmt.Scan(&x)
			if x <= 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				break
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
