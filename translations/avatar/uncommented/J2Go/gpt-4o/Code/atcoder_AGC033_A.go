package main

import (
	"container/list"
	"fmt"
)

func main() {
	var H, W int
	fmt.Scan(&H, &W)
	A := make([][]rune, H)
	queue := list.New()

	for i := 0; i < H; i++ {
		var row string
		fmt.Scan(&row)
		A[i] = []rune(row)
		for j := 0; j < W; j++ {
			if A[i][j] == '#' {
				start := [3]int{i, j, 0}
				queue.PushBack(start)
			}
		}
	}

	flag := make([][]int, H)
	for i := range flag {
		flag[i] = make([]int, W)
	}

	ans := 0
	dx := [4]int{1, -1, 0, 0}
	dy := [4]int{0, 0, 1, -1}

	for queue.Len() > 0 {
		temp := queue.Remove(queue.Front()).([3]int)
		y, x, depth := temp[0], temp[1], temp[2]

		for i := 0; i < 4; i++ {
			newY := y + dy[i]
			newX := x + dx[i]

			if newY >= 0 && newY < H && newX >= 0 && newX < W {
				if flag[newY][newX] == 0 && A[newY][newX] == '.' {
					flag[newY][newX] = 1
					queue.PushBack([3]int{newY, newX, depth + 1})
					ans = depth + 1
				}
			}
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
