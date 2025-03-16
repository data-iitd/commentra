package main

import (
	"fmt"
)

var d int
var n int
var mapGrid [105]string

func visit() {
	dx := [4]int{0, 1, 0, -1}
	dy := [4]int{-1, 0, 1, 0}
	var sum, flg int
	x, y := 2, n
	mapGrid[y] = replaceChar(mapGrid[y], x, ' ')
	ab := [4]int{2, 2, 2, 2}

	for {
		sum = 0
		for {
			if mapGrid[y+dy[flg]*2] != "#" && mapGrid[y+dy[flg]] != " " {
				flg++
				break
			}

			mapGrid[y+dy[flg]] = replaceChar(mapGrid[y+dy[flg]], x+dx[flg], ' ')
			y += dy[flg]
			x += dx[flg]
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

func replaceChar(s string, index int, newChar rune) string {
	runes := []rune(s)
	runes[index] = newChar
	return string(runes)
}

func main() {
	fmt.Scan(&d)

	for l := 0; l < d; l++ {
		fmt.Scan(&n)

		if n == 1 {
			fmt.Println("#")
			if l != d-1 {
				fmt.Println()
			}
			continue
		}

		for i := 0; i <= n+1; i++ {
			mapGrid[i] = ""
			for j := 0; j <= n+1; j++ {
				mapGrid[i] += "#"
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					mapGrid[i] = replaceChar(mapGrid[i], j, '.')
				}
			}
		}

		visit()

		for i := 1; i <= n; i++ {
			for j := 1; j < len(mapGrid[i])-1; j++ {
				fmt.Print(string(mapGrid[i][j]))
			}
			fmt.Println()
		}
		if l != d-1 {
			fmt.Println()
		}
	}
}

// <END-OF-CODE>
