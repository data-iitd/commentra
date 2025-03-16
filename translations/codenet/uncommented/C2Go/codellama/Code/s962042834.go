package main

import "fmt"

func kansu(a, b int) {
	var i, j, x, y, n int
	var suu [17][17]int
	var kouji [17][17]int

	fmt.Scan(&n)
	for i = 1; i <= a; i++ {
		for j = 1; j <= b; j++ {
			kouji[i][j] = 0
		}
	}
	for i = 0; i < n; i++ {
		fmt.Scan(&x, &y)
		kouji[x][y] = 1
	}
	for i = 1; i <= a; i++ {
		for j = 1; j <= b; j++ {
			if kouji[i][j] == 1 {
				suu[i][j] = 0
			} else {
				if i == 1 && j == 1 {
					suu[i][j] = 1
				} else {
					if i == 1 {
						suu[i][j] = suu[i][j-1]
					} else if j == 1 {
						suu[i][j] = suu[i-1][j]
					} else {
						suu[i][j] = suu[i][j-1] + suu[i-1][j]
					}
				}
			}
		}
	}
	fmt.Println(suu[a][b])
}

func main() {
	var a, b int

	fmt.Scan(&a, &b)
	for a != 0 && b != 0 {
		kansu(a, b)
		fmt.Scan(&a, &b)
	}
}

