
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	h, w int
	s     []string
	dx    = []int{0, 1, 0, -1, 1, 1, 1, -1, -1}
	dy    = []int{1, 0, -1, 0, 1, -1, 1, 1, -1}
	ans   = 1 << 30
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func dfs(x, y, cnt int) {
	if cnt > 20 {
		return
	}
	if x == h-1 {
		ans = min(ans, cnt)
		return
	}
	for i := 0; i < 8; i++ {
		nx, ny := x+dx[i], y+dy[i]
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			continue
		}
		if s[nx][ny]!= "X" {
			continue
		}
		c := true
		for c && s[nx][ny] == "X" {
			s[nx][ny] = "."
			nx += dx[i]
			ny += dy[i]
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					ans = min(ans, cnt+1)
				}
				c = false
			}
		}
		if c {
			dfs(nx, ny, cnt+1)
		}
		for nx!= x || ny!= y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx][ny] = "X"
		}
		s[x][y] = "."
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var sx, sy int
	for scanner.Scan() {
		s = append(s, scanner.Text())
	}
	h, w = len(s), len(s[0])
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == "O" {
				sx, sy = i, j
				s[i][j] = "."
			}
		}
	}
	dfs(sx, sy, 0)
	if ans == 1<<30 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

