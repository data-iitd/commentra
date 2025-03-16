package main

import (
	"bufio"
	"fmt"
	"os"
)

var seg = [][]bool{
	{true, true, true, true, true, true, true},
	{false, false, false, false, true, true, false},
	{true, false, true, true, false, true, true},
	{true, false, false, true, true, true, true},
	{true, true, false, false, true, true, false},
	{true, true, false, true, true, false, true},
	{true, true, true, true, true, false, true},
	{false, true, false, false, true, true, true},
	{true, true, true, true, true, true, true},
	{true, true, false, true, true, true, true},
}

func main() {
	in := bufio.NewScanner(os.Stdin)
	for in.Scan() {
		n := 0
		fmt.Sscanf(in.Text(), "%d", &n)
		if n == 0 {
			break
		}
		var st [7]bool
		for i := 0; i < n; i++ {
			in.Scan()
			t := 0
			fmt.Sscanf(in.Text(), "%d", &t)
			ans := make([]byte, 7)
			for j := 0; j < 7; j++ {
				ans[j] = '0' + byte(int(st[j])^seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
	}
}

