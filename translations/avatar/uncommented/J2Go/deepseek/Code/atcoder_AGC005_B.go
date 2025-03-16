package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N := toInt(scanner.Text())
	a := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		a[i] = toInt(scanner.Text())
	}
	leftl := make([]int, N)
	rightl := make([]int, N)
	que := []int{}
	index := 0
	for index < N {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			que = que[:len(que)-1]
			rightl[ind] = index - ind - 1
		}
		que = append(que, index)
		index++
	}
	for len(que) > 0 {
		ind := que[len(que)-1]
		que = que[:len(que)-1]
		rightl[ind] = N - ind - 1
	}
	index = N - 1
	for index >= 0 {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			que = que[:len(que)-1]
			leftl[ind] = ind - index - 1
		}
		que = append(que, index)
		index--
	}
	for len(que) > 0 {
		ind := que[len(que)-1]
		que = que[:len(que)-1]
		leftl[ind] = ind - index - 1
	}
	var ans int64 = 0
	for i := 0; i < N; i++ {
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}
	fmt.Println(ans)
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

