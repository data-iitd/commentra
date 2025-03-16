package main

import (
	"fmt"
)

var seg = [10][7]bool{
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

func main() {
	var n, t int
	st := make([]bool, 7)

	for {
		if _, err := fmt.Scan(&n); err != nil || n < 0 {
			break
		}
		for i := 0; i < 7; i++ {
			st[i] = false
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&t)
			ans := make([]byte, 7)
			for j := 0; j < 7; j++ {
				if st[j]^seg[t][j] {
					ans[j] = '1'
				} else {
					ans[j] = '0'
				}
				st[j] = seg[t][j]
			}
			fmt.Println(string(ans))
		}
	}
}

// <END-OF-CODE>
