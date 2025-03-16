package main

import (
	"fmt"
)

const N = 4

type Pazz struct {
	P [N][N]int
}

var Q Pazz
var dx = [4]int{0, 1, 0, -1}
var dy = [4]int{1, 0, -1, 0}

func Heu(Q Pazz) int {
	sum := 0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if Q.P[i][j] == 0 {
				continue
			}
			hx := (Q.P[i][j] - 1) % N - j
			hy := (Q.P[i][j] - 1) / N - i
			if hx < 0 {
				sum -= hx
			} else {
				sum += hx
			}
			if hy < 0 {
				sum -= hy
			} else {
				sum += hy
			}
		}
	}
	return sum
}

func dfs(x, y, max, count, n int) int {
	h := Heu(Q)
	if h == 0 {
		return count
	}
	if (count + h) > max {
		return -1
	}
	for i := 0; i < 4; i++ {
		x0 := x + dx[i]
		y0 := y + dy[i]
		if ((i == (n+2)%4) && (n != -1)) || !(0 <= x0 && x0 < N && 0 <= y0 && y0 < N) {
			continue
		}
		Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]
		ans := dfs(x0, y0, max, count+1, i)
		if ans != -1 {
			return ans
		}
		Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]
	}
	return -1
}

func main() {
	var i, j, a int
	var kx, ky int
	var ans int
	var tP Pazz

	for i = 0; i < N; i++ {
		for j = 0; j < N; j++ {
			fmt.Scan(&a)
			Q.P[i][j] = a
			if a == 0 {
				kx = j
				ky = i
			}
		}
	}

	tP = Q
	for i = 1; i < 46; i++ {
		Q = tP
		ans = dfs(kx, ky, i, 0, -1)
		if ans != -1 {
			fmt.Println(ans)
			break
		}
	}
}

