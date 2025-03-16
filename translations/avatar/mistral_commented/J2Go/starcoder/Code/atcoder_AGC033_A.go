
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
	fmt.Println("Enter the number of rows and columns of the grid:")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, "\r", "", -1)
	input = strings.Replace(input, "\t", "", -1)
	input = strings.Replace(input, " ", "", -1)
	input_arr := strings.Split(input, ",")
	H, _ := strconv.Atoi(input_arr[0])
	W, _ := strconv.Atoi(input_arr[1])
	fmt.Println("Enter the grid:")
	A := make([][]byte, H)
	for i := 0; i < H; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		input = strings.Replace(input, "\n", "", -1)
		input = strings.Replace(input, "\r", "", -1)
		input = strings.Replace(input, "\t", "", -1)
		input = strings.Replace(input, " ", "", -1)
		A[i] = []byte(input)
	}
	queue := make([][]int, 0)
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if A[i][j] == byte('#') {
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
			newY := y + dy[i]
			newX := x + dx[i]
			if newY >= 0 && newY < H && newX >= 0 && newX < W {
				if flag[newY][newX] == 0 && A[newY][newX] == byte('.') {
					flag[newY][newX] = 1
					queue = append(queue, []int{newY, newX, depth + 1})
					ans = max(ans, depth + 1)
				}
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

