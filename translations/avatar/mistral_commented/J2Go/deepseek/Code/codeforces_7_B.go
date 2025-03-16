package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var t, m int
	fmt.Scan(&t, &m)
	memory := make([]int, m)
	var allocIdx int

	for i := 0; i < t; i++ {
		scanner.Scan()
		command := scanner.Text()

		switch command {
		case "alloc":
			var n int
			fmt.Scan(&n)
			len := 0
			canAlloc := false
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
			var x int
			fmt.Scan(&x)
			if x <= 0 {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
				continue
			}
			hasErased := false
			for j := 0; j < m; j++ {
				if memory[j] == x {
					memory[j] = 0
					hasErased = true
				}
			}
			if !hasErased {
				fmt.Println("ILLEGAL_ERASE_ARGUMENT")
			}
		case "defragment":
			d := 0
			for j := 0; j < m; j++ {
				if memory[j] == 0 {
					d++
				}
			}
			newSize := m - d
			newMemory := make([]int, newSize)
			k := 0
			for j := 0; j < m; j++ {
				if memory[j] != 0 {
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

