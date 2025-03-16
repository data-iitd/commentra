package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var d int
var map1 [105]string
var n int

func visit() {
	dx := [4]int{0, 1, 0, -1}
	dy := [4]int{-1, 0, 1, 0}
	sum, flg := 0, 0
	x, y := 2, n
	map1[y] = map1[y][:x] + " " + map1[y][x+1:]
	ab := [4]int{2, 2, 2, 2}

	for {
		sum = 0
		for {
			if map1[y+dy[flg]*2][x+dx[flg]*2] != '#' && map1[y+dy[flg]][x+dx[flg]] != ' ' {
				flg++
				break
			}

			map1[y+dy[flg]] = map1[y+dy[flg]][:x+dx[flg]] + " " + map1[y+dy[flg]][x+dx[flg]+1:]
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
		ab[0], ab[1], ab[2] = ab[1], ab[2], sum
		if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
			break
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &d)

	for l := 0; l < d; l++ {
		fmt.Fscan(reader, &n)

		if n == 1 {
			fmt.Println("#")
			if l != d-1 {
				fmt.Println()
			}
			continue
		}

		for i := 0; i <= n+1; i++ {
			map1[i] = strings.Repeat("#", n+2)
			for j := 0; j <= n+1; j++ {
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map1[i] = map1[i][:j] + "." + map1[i][j+1:]
				}
			}
		}

		visit()

		for i := 1; i <= n; i++ {
			for j := 1; j < len(map1[i])-1; j++ {
				fmt.Print(string(map1[i][j]))
			}
			fmt.Println()
		}
		if l != d-1 {
			fmt.Println()
		}
	}
}
