
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
	var n int
	var len int
	var canAlloc bool
	var x int
	var hasErased bool
	var d int
	var newSize int
	var newMemory [1000000]int
	var k int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var command string
		fmt.Fscan(reader, &command)
		switch command {
		case "alloc":
			fmt.Fscan(reader, &n)
			len = 0
			canAlloc = false
			for j := 0; j < m; j++ {
				if memory[j] == 0 {
					len++
				} else {
					len = 0
				}
				if len == n {
					canAlloc = true
					len = j - n + 1
					break
				}
			}
			if canAlloc {
				allocIdx++
				for j := len; j < len+n; j++ {
					memory[j] = allocIdx
				}
				fmt.Println(allocIdx)
			} else {
				fmt.Println("NULL")
			}
		case "erase":
			fmt.Fscan(reader, &x)
			if x <= 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				break
			}
			hasErased = false
			for j := 0; j < m; j++ {
				if memory[j] == x {
					memory[j] = 0
					hasErased = true
				}
			}
			if!hasErased {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			}
		case "defragment":
			d = 0
			for j := 0; j < m; j++ {
				if memory[j] == 0 {
					d++
				}
			}
			newSize = m - d
			newMemory = [1000000]int{}
			k = 0
			for j := 0; j < m; j++ {
				if memory[j]!= 0 {
					newMemory[k] = memory[j]
					k++
				}
			}
			memory = newMemory
		default:
			fmt.Println("h")
		}
	}
}

