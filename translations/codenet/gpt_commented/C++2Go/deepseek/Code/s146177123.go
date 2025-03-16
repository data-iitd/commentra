package main

import (
	"bufio"
	"fmt"
	"os"
)

// Segment representation for digits 0-9
var seg = [][]bool{
	{0, 1, 1, 1, 1, 1, 1}, // 0
	{0, 0, 0, 0, 1, 1, 0}, // 1
	{1, 0, 1, 1, 0, 1, 1}, // 2
	{1, 0, 0, 1, 1, 1, 1}, // 3
	{1, 1, 0, 0, 1, 1, 0}, // 4
	{1, 1, 0, 1, 1, 0, 1}, // 5
	{1, 1, 1, 1, 1, 0, 1}, // 6
	{0, 1, 0, 0, 1, 1, 1}, // 7
	{1, 1, 1, 1, 1, 1, 1}, // 8
	{1, 1, 0, 1, 1, 1, 1}, // 9
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		var n, t int
		fmt.Scan(&n)
		if n < 0 {
			break
		}
		var st [7]bool
		for i := 0; i < n; i++ {
			fmt.Scan(&t)
			ans := [7]rune{}
			for i := 0; i < 7; i++ {
				ans[i] = '0' + '1' - ('0' + (st[i] != seg[t][i]))
				st[i] = seg[t][i]
			}
			fmt.Println(string(ans[:]))
		}
	}
}

