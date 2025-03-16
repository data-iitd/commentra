package main

import (
	"fmt"
)

func solveCase() {
	var n, m int
	fmt.Scan(&n, &m)
	count := make([][]int, n)
	for i := range count {
		count[i] = make([]int, n)
	}
	ans := -1
	for k := 0; k < m; k++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		found := false
		for i := x - 2; i <= x; i++ {
			for j := y - 2; j <= y; j++ {
				if i >= 0 && i < n && j >= 0 && j < n {
					count[i][j]++
					if count[i][j] == 9 {
						found = true
					}
				}
			}
		}
		if found {
			ans = k + 1
			break
		}
	}
	fmt.Println(ans)
}

func main() {
	solveCase()
}

// <END-OF-CODE>
