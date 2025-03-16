
package main

import (
	"fmt"
	"math"
	"strings"
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
	//fmt.Println(x, y, cnt)
	//fmt.Println(s)
	if x == len(s)-1 {
		ans = int(math.Min(float64(ans), float64(cnt)))
		return
	}
	for i := 0; i < 8; i++ {
		nx := x + dx[i]
		ny := y + dy[i]
		if nx < 0 || nx >= len(s) || ny < 0 || ny >= len(s[0]) {
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
			if nx < 0 || nx >= len(s) || ny < 0 || ny >= len(s[0]) {
				if nx >= len(s) {
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

var (
	s   []string
	ans = math.MaxInt32
	dx  = []int{0, 1, 0, -1, 1, 1, -1, -1}
	dy  = []int{1, 0, -1, 0, 1, -1, 1, -1}
)

func main() {
	s = strings.Split(strings.TrimSpace(string([]byte(read()))), "\n")
	var sx, sy int
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(s[0]); j++ {
			if s[i][j] == 'O' {
				sx = i
				sy = j
				s[i][j] = '.'
			}
		}
	}
	dfs(sx, sy, 0)
	if ans == math.MaxInt32 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

func read() string {
	var s string
	_, err := fmt.Scan(&s)
	if err != nil {
		panic(err)
	}
	return s
}

