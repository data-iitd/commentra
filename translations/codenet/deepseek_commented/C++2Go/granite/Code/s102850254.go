
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	d int
	n int
	map_ [105][105]string
)

func visit() {
	dx := []int{0, 1, 0, -1}
	dy := []int{-1, 0, 1, 0}
	sum, flg := 0, 0
	x, y := 2, n
	map_[y][x] = " "
	ab := []int{2, 2, 2, 2}

	for {
		sum = 0
		for {
			if map_[y+dy[flg]*2][x+dx[flg]*2]!= "#" && map_[y+dy[flg]][x+dx[flg]]!= " " {
				flg++
				break
			}
			map_[y+dy[flg]][x+dx[flg]] = " "
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
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var err error
	d, err = strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}

	for l := 0; l < d; l++ {
		fmt.Fscanf(scanner, "%d\n", &n)

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

