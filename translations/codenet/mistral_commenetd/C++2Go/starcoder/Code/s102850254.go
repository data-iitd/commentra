
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var d int
	fmt.Scanf("%d", &d)
	for i := 0; i < d; i++ {
		var n int
		fmt.Scanf("%d", &n)
		if n == 1 {
			fmt.Println("#")
			if i!= d-1 {
				fmt.Println()
			}
			continue
		}
<<<<<<< HEAD
		var map [105][105]byte
		for i := 0; i <= n+1; i++ {
			for j := 0; j <= n+1; j++ {
				map[i][j] = '#'
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map[i][j] = '.'
=======
		var map [105][105]string
		for i := 0; i <= n+1; i++ {
			for j := 0; j <= n+1; j++ {
				map[i][j] = "#"
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map[i][j] = "."
>>>>>>> 98c87cb78a (data updated)
				}
			}
		}
		var x, y, sum, flg int
<<<<<<< HEAD
		x, y = 2, n
		var temp byte
		for {
			sum, flg = 0, 0
			for i := 0; i < 4; i++ {
				if map[y+dy[i]*2][x+dx[i]*2]!= '#' && map[y+dy[i]][x+dx[i]]!='' {
					flg++
					map[y+dy[i]][x+dx[i]] =''
					y += dy[i]
					x += dx[i]
=======
		x = 2
		y = n
		var temp string
		for {
			sum = 0
			flg = 0
			for {
				if map[y+dy[flg]][x+dx[flg]]!= "#" && map[y+dy[flg]][x+dx[flg]]!= " " {
					flg++
					map[y+dy[flg]][x+dx[flg]] = " "
					y = y + dy[flg]
					x = x + dx[flg]
>>>>>>> 98c87cb78a (data updated)
					sum++
					break
				}
			}
			if flg == 4 {
				flg = 0
				if sum == 0 {
					break
				}
				var ab [4]int
<<<<<<< HEAD
				ab[0], ab[1], ab[2] = ab[1], ab[2], sum
=======
				ab[0] = ab[1]
				ab[1] = ab[2]
				ab[2] = sum
>>>>>>> 98c87cb78a (data updated)
				if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 {
					break
				}
			}
		}
		for i := 1; i <= n; i++ {
			for j := 1; j < len(map[i])-1; j++ {
<<<<<<< HEAD
				fmt.Printf("%c", map[i][j])
=======
				fmt.Print(map[i][j])
>>>>>>> 98c87cb78a (data updated)
			}
			fmt.Println()
		}
		if i!= d-1 {
			fmt.Println()
		}
	}
}

