
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	H, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	W, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	A := make([][]rune, H)
	for i := 0; i < H; i++ {
		A[i] = []rune(readLine(reader))
	}

	queue := make([][]int, 0)
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if A[i][j] == '#' {
				queue = append(queue, []int{i, j, 0})
			}
		}
	}

	flag := make([][]int, H)
	for i := 0; i < H; i++ {
		flag[i] = make([]int, W)
	}

	ans := 0
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	for len(queue) > 0 {
		temp := queue[0]
		queue = queue[1:]

		y := temp[0]
		x := temp[1]
		depth := temp[2]

		for i := 0; i < 4; i++ {
			if 0 <= y+dy[i] && y+dy[i] < H && 0 <= x+dx[i] && x+dx[i] < W {
				if flag[y+dy[i]][x+dx[i]] == 0 && A[y+dy[i]][x+dx[i]] == '.' {
					flag[y+dy[i]][x+dx[i]] = 1
					queue = append(queue, []int{y + dy[i], x + dx[i], depth + 1})
					ans = depth + 1
				}
			}
		}
	}

	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

