package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		h, w int
		s    [19]string
		ans  int = math.MaxInt32
	)
	fmt.Scanf("%d %d", &h, &w)
	for i := 0; i < h; i++ {
		fmt.Scanf("%s", &s[i])
	}
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == 'O' {
				s[i][j] = '.'
				for k := 0; k < 8; k++ {
					x, y := i+dx[k], j+dy[k]
					if x < 0 || x >= h || y < 0 || y >= w {
						if x >= h {
							ans = min(ans, dfs(s, i, j, 0))
						}
						continue
					}
					if s[x][y]!= 'X' {
						continue
					}
					for {
						s[x][y] = '.'
						x += dx[k]
						y += dy[k]
						if x < 0 || x >= h || y < 0 || y >= w {
							if x >= h {
								ans = min(ans, dfs(s, i, j, 0)+1)
							}
							break
						}
					}
				}
				s[i][j] = 'O'
			}
		}
	}
	if ans == math.MaxInt32 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func dfs(s [19]string, x, y, cnt int) int {
	if cnt > 20 {
		return cnt
	}
	if x == 18 {
		return cnt
	}
	for i := 0; i < 8; i++ {
		nx, ny := x+dx[i], y+dy[i]
		if nx < 0 || nx >= 19 || ny < 0 || ny >= 15 {
			continue
		}
		if s[nx][ny]!= 'X' {
			continue
		}
		for {
			s[nx][ny] = '.'
			nx += dx[i]
			ny += dy[i]
			if nx < 0 || nx >= 19 || ny < 0 || ny >= 15 {
				if nx >= 19 {
					return cnt + 1
				}
				break
			}
		}
	}
	for i := 0; i < 8; i++ {
		nx, ny := x+dx[i], y+dy[i]
		if nx < 0 || nx >= 19 || ny < 0 || ny >= 15 {
			continue
		}
		if s[nx][ny]!= 'O' {
			continue
		}
		s[nx][ny] = '.'
		cnt = dfs(s, nx, ny, cnt+1)
		s[nx][ny] = 'O'
	}
	return cnt
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func printArray(a []int) {
	for i := 0; i < len(a); i++ {
		fmt.Printf("%d ", a[i])
	}
	fmt.Println()
}

func printArray2D(a [][]int) {
	for i := 0; i < len(a); i++ {
		printArray(a[i])
	}
	fmt.Println()
}

func printArray3D(a [][][]int) {
	for i := 0; i < len(a); i++ {
		printArray2D(a[i])
	}
	fmt.Println()
}

func printArray4D(a [][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray3D(a[i])
	}
	fmt.Println()
}

func printArray5D(a [][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray4D(a[i])
	}
	fmt.Println()
}

func printArray6D(a [][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray5D(a[i])
	}
	fmt.Println()
}

func printArray7D(a [][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray6D(a[i])
	}
	fmt.Println()
}

func printArray8D(a [][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray7D(a[i])
	}
	fmt.Println()
}

func printArray9D(a [][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray8D(a[i])
	}
	fmt.Println()
}

func printArray10D(a [][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray9D(a[i])
	}
	fmt.Println()
}

func printArray11D(a [][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray10D(a[i])
	}
	fmt.Println()
}

func printArray12D(a [][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray11D(a[i])
	}
	fmt.Println()
}

func printArray13D(a [][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray12D(a[i])
	}
	fmt.Println()
}

func printArray14D(a [][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray13D(a[i])
	}
	fmt.Println()
}

func printArray15D(a [][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray14D(a[i])
	}
	fmt.Println()
}

func printArray16D(a [][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray15D(a[i])
	}
	fmt.Println()
}

func printArray17D(a [][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray16D(a[i])
	}
	fmt.Println()
}

func printArray18D(a [][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray17D(a[i])
	}
	fmt.Println()
}

func printArray19D(a [][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray18D(a[i])
	}
	fmt.Println()
}

func printArray20D(a [][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray19D(a[i])
	}
	fmt.Println()
}

func printArray21D(a [][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray20D(a[i])
	}
	fmt.Println()
}

func printArray22D(a [][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray21D(a[i])
	}
	fmt.Println()
}

func printArray23D(a [][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray22D(a[i])
	}
	fmt.Println()
}

func printArray24D(a [][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray23D(a[i])
	}
	fmt.Println()
}

func printArray25D(a [][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray24D(a[i])
	}
	fmt.Println()
}

func printArray26D(a [][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray25D(a[i])
	}
	fmt.Println()
}

func printArray27D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray26D(a[i])
	}
	fmt.Println()
}

func printArray28D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray27D(a[i])
	}
	fmt.Println()
}

func printArray29D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray28D(a[i])
	}
	fmt.Println()
}

func printArray30D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray29D(a[i])
	}
	fmt.Println()
}

func printArray31D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray30D(a[i])
	}
	fmt.Println()
}

func printArray32D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray31D(a[i])
	}
	fmt.Println()
}

func printArray33D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray32D(a[i])
	}
	fmt.Println()
}

func printArray34D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray33D(a[i])
	}
	fmt.Println()
}

func printArray35D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray34D(a[i])
	}
	fmt.Println()
}

func printArray36D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray35D(a[i])
	}
	fmt.Println()
}

func printArray37D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray36D(a[i])
	}
	fmt.Println()
}

func printArray38D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray37D(a[i])
	}
	fmt.Println()
}

func printArray39D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray38D(a[i])
	}
	fmt.Println()
}

func printArray40D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray39D(a[i])
	}
	fmt.Println()
}

func printArray41D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray40D(a[i])
	}
	fmt.Println()
}

func printArray42D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray41D(a[i])
	}
	fmt.Println()
}

func printArray43D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray42D(a[i])
	}
	fmt.Println()
}

func printArray44D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray43D(a[i])
	}
	fmt.Println()
}

func printArray45D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray44D(a[i])
	}
	fmt.Println()
}

func printArray46D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray45D(a[i])
	}
	fmt.Println()
}

func printArray47D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray46D(a[i])
	}
	fmt.Println()
}

func printArray48D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray47D(a[i])
	}
	fmt.Println()
}

func printArray49D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray48D(a[i])
	}
	fmt.Println()
}

func printArray50D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]int) {
	for i := 0; i < len(a); i++ {
		printArray49D(a[i])
	}
	fmt.Println()
}

func printArray51D(a [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]