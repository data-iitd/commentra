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
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, N)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	leftl := make([]int, N)
	rightl := make([]int, N)
	que := make([]int, 0)
	index := 0
	for index < N {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			rightl[ind] = index - ind - 1
			que = que[:len(que)-1]
		}
		que = append(que, index)
		index++
	}
	for len(que) > 0 {
		ind := que[len(que)-1]
		rightl[ind] = N - ind - 1
		que = que[:len(que)-1]
	}
	index = N - 1
	for index >= 0 {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			leftl[ind] = ind - index - 1
			que = que[:len(que)-1]
		}
		que = append(que, index)
		index--
	}
	for len(que) > 0 {
		ind := que[len(que)-1]
		leftl[ind] = ind - index - 1
		que = que[:len(que)-1]
	}
	ans := 0
	for i := 0; i < N; i++ {
		ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
	}
	fmt.Println(ans)
}

