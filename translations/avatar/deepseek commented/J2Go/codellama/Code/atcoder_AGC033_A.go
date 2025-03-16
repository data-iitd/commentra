package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var H, W int
	scanner.Scan()
	H, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	W, _ = strconv.Atoi(scanner.Text())
	A := make([][]rune, H)
	for i := 0; i < H; i++ {
		A[i] = make([]rune, W)
		scanner.Scan()
		for j := 0; j < W; j++ {
			A[i][j] = rune(scanner.Text()[j])
			if A[i][j] == '#' {
				queue := make([][]int, 0)
				queue = append(queue, []int{i, j, 0})
				flag := make([][]int, H)
				for i := 0; i < H; i++ {
					flag[i] = make([]int, W)
				}
				dx := []int{1, -1, 0, 0}
				dy := []int{0, 0, 1, -1}
				ans := 0
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
		}
	}
}

