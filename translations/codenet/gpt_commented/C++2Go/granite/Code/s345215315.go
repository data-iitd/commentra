
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var ans int = 1000000000
var h int = 19
var w int = 15
var dx = []int{0, 1, 0, -1, 1, 1, 1, -1, -1}
var dy = []int{1, 0, -1, 0, 1, -1, 1, 1, -1}
var s = make([]string, h)

func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a int, b int) int {
	return a / gcd(a, b) * b
}

func dfs(x int, y int, cnt int) {
	if cnt > 20 {
		return
	}
	if x == h-1 {
		if ans > cnt {
			ans = cnt
		}
		return
	}
	for i := 0; i < 8; i++ {
		nx := x + dx[i]
		ny := y + dy[i]
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			if nx >= h {
				if ans > cnt+1 {
					ans = cnt + 1
				}
			}
			continue
		}
		if s[nx][ny]!= 'X' {
			continue
		}
		c := true
		for c && s[nx][ny] == 'X' {
			s[nx][ny] = '.'
			nx += dx[i]
			ny += dy[i]
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					if ans > cnt+1 {
						ans = cnt + 1
					}
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
			s[nx][ny] = 'X'
		}
		s[x][y] = '.'
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var sx int
	var sy int
	for scanner.Scan() {
		s[sx] = scanner.Text()
		sx++
	}
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == 'O' {
				sx = i
				sy = j
				s[i][j] = '.'
			}
		}
	}
	dfs(sx, sy, 0)
	if ans == 1000000000 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// Translate the above Go code to Rust and end with comment "