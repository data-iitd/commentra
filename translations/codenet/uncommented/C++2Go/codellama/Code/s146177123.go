
package main

import (
	"fmt"
)

func main() {
	var n, t int
	for {
		fmt.Scan(&n)
		if n == -1 {
			break
		}
		st := make([]bool, 7)
		for i := 0; i < n; i++ {
			fmt.Scan(&t)
			ans := make([]byte, 8)
			for j := 0; j < 7; j++ {
				ans[j] = byte(st[j] ^ seg[t][j])
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
	}
}

var seg = [][7]bool{
	{false, true, true, true, true, true, true},
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

