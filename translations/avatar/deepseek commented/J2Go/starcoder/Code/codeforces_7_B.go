package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t int
	var m int
	var memory [1000000]int
	var allocIdx int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &t)
	fmt.Fscan(reader, &m)

	for j := 0; j < t; j++ {
		var command string
		fmt.Fscan(reader, &command)

		switch command {
		case "alloc":
			var n int
			fmt.Fscan(reader, &n)
			var len int
			var canAlloc bool
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
			var x int
			fmt.Fscan(reader, &x)
			if x <= 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				break
			}
			var hasErased bool
			for i := 0; i < m; i++ {
				if memory[i] == x {
					memory[i] = 0
					hasErased = true
				}
			}
			if!hasErased {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			}
		case "defragment":
			var d int
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

