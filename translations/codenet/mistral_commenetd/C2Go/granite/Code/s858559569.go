

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const N = 4

type Pazz struct {
	P [N][N]int
}

var dx = [4]int{0, 1, 0, -1}
var dy = [4]int{1, 0, -1, 0}

func Heu(Q Pazz) int {
	i, j, hx, hy, sum := 0, 0, 0, 0, 0
	for i = 0; i < N; i++ {
		for j = 0; j < N; j++ {
			if Q.P[i][j] == 0 {
				continue
			}
			hx = (Q.P[i][j] - 1) % N - j
			hy = (Q.P[i][j] - 1) / N - i
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
	i, temp, x0, y0, ans := 0, 0, 0, 0, -1
	h := Heu(Q)
	if h == 0 {
		return count
	}
	if (count + h) > max {
		return -1
	}
	for i = 0; i < 4; i++ {
		x0 = x + dx[i]
		y0 = y + dy[i]
		if ((i == (n+2)%4) && (n!= -1)) ||!((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N)) {
			continue
		}
		temp = Q.P[y][x]
		Q.P[y][x] = Q.P[y0][x0]
		Q.P[y0][x0] = temp
		ans = dfs(x0, y0, max, count+1, i)
		if ans!= -1 {
			return ans
		}
		temp = Q.P[y][x]
		Q.P[y][x] = Q.P[y0][x0]
		Q.P[y0][x0] = temp
	}
	return -1
}

func main() {
	var i, j, kx, ky, ans, a int
	var tP Pazz
	scanner := bufio.NewScanner(os.Stdin)
	for i = 0; i < N; i++ {
		for j = 0; j < N; j++ {
			scanner.Scan()
			a, _ = strconv.Atoi(scanner.Text())
			Q.P[i][j] = a
			if a == 0 {
				kx = j
				ky = i
			}
		}
	}
	tP = Q
	ans = dfs(kx, ky, 46, 0, -1)
	if ans!= -1 {
		fmt.Println(ans)
	} else {
		fmt.Println("No solution found")
	}
}

