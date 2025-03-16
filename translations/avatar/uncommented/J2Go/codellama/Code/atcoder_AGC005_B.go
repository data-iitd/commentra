
package main

import (
	"fmt"
	"os"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}
	leftl := make([]int, N)
	rightl := make([]int, N)
	que := make([]int, 0)
	index := 0
	for index < N {
		for !que.isEmpty() && a[que.peek()] > a[index] {
			ind := que.poll()
			rightl[ind] = index - ind - 1
		}
		que.push(index)
		index++
	}
	for !que.isEmpty() {
		ind := que.poll()
		rightl[ind] = N - ind - 1
	}
	index = N - 1
	for index >= 0 {
		for !que.isEmpty() && a[que.peek()] > a[index] {
			ind := que.poll()
			leftl[ind] = ind - index - 1
		}
		que.push(index)
		index--
	}
	for !que.isEmpty() {
		ind := que.poll()
		leftl[ind] = ind - index - 1
	}
	ans := 0
	for i := 0; i < N; i++ {
		ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
	}
	fmt.Println(ans)
}

