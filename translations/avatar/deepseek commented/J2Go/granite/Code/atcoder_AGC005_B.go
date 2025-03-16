
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine())
	}
	leftl := make([]int, n)
	rightl := make([]int, n)
	que := make([]int, 0)
	index := 0
	for index < n {
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
		rightl[ind] = n - ind - 1
	}
	index = n - 1
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
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(a[i]) * (int64(leftl[i]) + 1) * (int64(rightl[i]) + 1)
	}
	fmt.Println(ans)
}

