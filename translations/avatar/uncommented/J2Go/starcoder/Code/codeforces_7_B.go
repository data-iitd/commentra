package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of test cases")
	tc, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	for i := 0; i < tc; i++ {
		fmt.Println("Enter the number of memory blocks")
		m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		fmt.Println("Enter the number of operations")
		t, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		memory := make([]int, m)
		allocIdx := 0
		for j := 0; j < t; j++ {
			fmt.Println("Enter the operation")
			op := strings.TrimSpace(reader.ReadString('\n'))
			switch op {
			case "alloc":
				fmt.Println("Enter the number of blocks to be allocated")
				n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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
				fmt.Println("Enter the block to be erased")
				x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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
				if!hasErased {
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
}

