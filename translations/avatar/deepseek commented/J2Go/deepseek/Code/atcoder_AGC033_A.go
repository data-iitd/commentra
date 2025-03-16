package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	var H, W int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &H)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &W)
	
	A := make([][]rune, H)
	queue := [][]int{}
	
	for i := 0; i < H; i++ {
		scanner.Scan()
		row := scanner.Text()
		A[i] = []rune(row)
		for j := 0; j < W; j++ {
			if A[i][j] == '#' {
				queue = append(queue, []int{i, j, 0})
			}
		}
	}
	
	flag := make([][]int, H)
	for i := range flag {
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
			if 0 <= y + dy[i] && y + dy[i] <= H - 1 && 0 <= x + dx[i] && x + dx[i] <= W - 1 {
				if flag[y + dy[i]][x + dx[i]] == 0 && A[y + dy[i]][x + dx[i]] == '.' {
					flag[y + dy[i]][x + dx[i]] = 1
					queue = append(queue, []int{y + dy[i], x + dx[i], depth + 1})
					if depth + 1 > ans {
						ans = depth + 1
					}
				}
			}
		}
	}
	
	fmt.Println(ans)
}
