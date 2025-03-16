package main

import (
	"fmt"
	"math"
)

const (
	INF = 1e9
	h   = 19
	w   = 15
)

var (
	ans = INF
	s   [h][w]rune
	dx  = [8]int{0, 1, 0, -1, 1, 1, -1, -1}
	dy  = [8]int{1, 0, -1, 0, 1, -1, 1, -1}
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
		ans = int(math.Min(float64(ans), float64(cnt)))
		return
	}
	for i := 0; i < 8; i++ {
		nx, ny := x+dx[i], y+dy[i]
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			continue
		}
		if s[nx][ny] != 'X' {
			continue
		}
		c := true
		for c && s[nx][ny] == 'X' {
			s[nx][ny] = '.'
			nx += dx[i]
			ny += dy[i]
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					ans = int(math.Min(float64(ans), float64(cnt+1)))
				}
				c = false
			}
		}
		if c {
			dfs(nx, ny, cnt+1)
		}
		for nx != x || ny != y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx][ny] = 'X'
		}
		s[x][y] = '.'
	}
}

func main() {
	var sx, sy int
	for i := 0; i < h; i++ {
		var line string
		fmt.Scan(&line)
		for j := 0; j < w; j++ {
			s[i][j] = rune(line[j])
			if s[i][j] == 'O' {
				sx, sy = i, j
				s[i][j] = '.'
			}
		}
	}
	dfs(sx, sy, 0)
	if ans == INF {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
