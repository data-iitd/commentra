package main

import (
	"bufio"
	"fmt"
	"os"
)

// Array to represent the segments of the digits 0-9
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
	in := bufio.NewScanner(os.Stdin)
	for in.Scan() {
		n, _ := fmt.Sscanf(in.Text(), "%d", &n)
		if n == 0 {
			break
		}
		var st [7]bool
		for i := 0; i < n; i++ {
			in.Scan()
			t, _ := fmt.Sscanf(in.Text(), "%d", &t)
			if t < 0 || t > 9 {
				continue
			}
			ans := [7]rune{}
			for i := 0; i < 7; i++ {
				ans[i] = rune('0' + (st[i] != seg[t][i]))
				st[i] = seg[t][i]
			}
			fmt.Println(string(ans[:]))
		}
	}
}

