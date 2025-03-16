package main

import (
	"fmt"
)

func visit() {
	dx := []int{0, 1, 0, -1}
	dy := []int{-1, 0, 1, 0}
	sum, flg := 0, 0
	x, y := 2, n
	map[y][x] = ' '
	ab := []int{2, 2, 2, 2}

	for {
		sum = 0
		for {
			if map[y+dy[flg]*2][x+dx[flg]*2] != '#' && map[y+dy[flg]][x+dx[flg]] != ' ' {
				flg++
				//  cout << sum << endl;

				break
			}

			map[y+dy[flg]][x+dx[flg]] = ' '
			y = y + dy[flg]
			x = x + dx[flg]
			sum++
		}
		if flg == 4 {
			flg = 0
		}
		if sum == 0 {
			break
		}
		ab[0] = ab[1]
		ab[1] = ab[2]
		ab[2] = sum
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
			break
		}
	}
}

func main() {
	var d int
	fmt.Scan(&d)

	for l := 0; l < d; l++ {
		var n int
		fmt.Scan(&n)

		if n == 1 {
			fmt.Println("#")
			if l != d-1 {
				fmt.Println()
			}
			continue
		}

		for i := 0; i <= n+1; i++ {
			map[i] = make([]byte, n+2)
			for j := 0; j <= n+1; j++ {
				map[i][j] = '#'
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map[i][j] = '.'
				}
			}
		}

		visit()

		for i := 1; i <= n; i++ {
			for j := 1; j < len(map[i])-1; j++ {
				fmt.Printf("%c", map[i][j])
			}
			fmt.Println()
		}
		if l != d-1 {
			fmt.Println()
		}
	}
}

