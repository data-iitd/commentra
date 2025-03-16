
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var t, m int
	var memory []int
	var allocIdx int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &t, &m)
	memory = make([]int, m)
	for j := 0; j < t; j++ {
		var op string
		fmt.Fscanf(reader, "%s\n", &op)
		switch op {
		case "alloc":
			var n int
			fmt.Fscanf(reader, "%d\n", &n)
			var len, start int
			var canAlloc bool
			for i := 0; i < m; i++ {
				if memory[i] == 0 {
					len++
				} else {
					len = 0
				}
				if len == n {
					canAlloc = true
					start = i - n + 1
					break
				}
			}
			if canAlloc {
				allocIdx++
				for i := start; i < start+n; i++ {
					memory[i] = allocIdx
				}
				fmt.Println(allocIdx)
			} else {
				fmt.Println("NULL")
			}
		case "erase":
			var x int
			fmt.Fscanf(reader, "%d\n", &x)
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
