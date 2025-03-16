

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	d int
	n int
	map_ [105][105]string
	dx = []int{0, 1, 0, -1}
	dy = []int{-1, 0, 1, 0}
	sum int
	flg int
	x int
	y int
	temp string
	ab = []int{2, 2, 2, 2}
)

func visit() {
	// function to find the path of 'O' in the grid
	for {
		sum = 0
		flg = 0
		for {
			if map_[y+dy[flg]*2][x+dx[flg]*2]!= "#" && map_[y+dy[flg]][x+dx[flg]]!= " " {
				flg++
				map_[y+dy[flg]][x+dx[flg]] = " "
				y = y + dy[flg]
				x = x + dx[flg]
				sum++
				break
			}
		}
		if flg == 4 {
			flg = 0
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
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Scan(&d)
	for l := 0; l < d; l++ {
		fmt.Scan(&n)
		if n == 1 {
			fmt.Println("#")
			if l!= d-1 {
				fmt.Println()
			}
			continue
		}
		for i := 0; i <= n+1; i++ {
			map_[i] = make([]string, n+2)
			for j := 0; j <= n+1; j++ {
				map_[i][j] = "#"
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map_[i][j] = "."
				}
			}
		}
		visit()
		for i := 1; i <= n; i++ {
			for j := 1; j < len(map_[i])-1; j++ {
				fmt.Print(map_[i][j])
			}
			fmt.Println()
		}
		if l!= d-1 {
			fmt.Println()
		}
	}
}

