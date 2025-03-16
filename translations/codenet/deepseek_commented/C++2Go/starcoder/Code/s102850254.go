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
		m := make([]string, n+2)
		for j := 0; j < n+2; j++ {
			m[j] = strings.Repeat("#", n+2)
		}
		for j := 0; j < n+2; j++ {
			m[0][j] = "."
			m[n+1][j] = "."
		}
		for j := 1; j <= n; j++ {
			m[j][0] = "."
			m[j][n+1] = "."
		}
		var x, y, sum, flg int
		x, y = 2, n
		m[y][x] = " "
		ab := make([]int, 4)
		for {
			sum = 0
			for {
				if m[y+dy[flg]][x+dx[flg]]!= "#" && m[y+dy[flg]][x+dx[flg]]!= " " {
					flg++
					break
				}
				m[y+dy[flg]][x+dx[flg]] = " "
				y += dy[flg]
				x += dx[flg]
				sum++
				if flg == 4 {
					flg = 0
				}
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
		for j := 1; j <= n; j++ {
			fmt.Println(m[j][1:n+1])
		}
		if i!= d-1 {
			fmt.Println()
		}
	}
}

<<<<<<< HEAD
const (
	dx = [4]int{0, 1, 0, -1}
	dy = [4]int{-1, 0, 1, 0}
)

=======
const END_OF_CODE = "
>>>>>>> 98c87cb78a (data updated)
