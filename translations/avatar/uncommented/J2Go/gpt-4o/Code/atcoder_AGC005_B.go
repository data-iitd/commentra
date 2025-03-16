package main

import (
	"container/list"
	"fmt"
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
	que := list.New()

	index := 0
	for index < N {
		for que.Len() > 0 && a[que.Back().Value.(int)] > a[index] {
			ind := que.Remove(que.Back()).(int)
			rightl[ind] = index - ind - 1
		}
		que.PushBack(index)
		index++
	}
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		rightl[ind] = N - ind - 1
	}

	index = N - 1
	for index >= 0 {
		for que.Len() > 0 && a[que.Back().Value.(int)] > a[index] {
			ind := que.Remove(que.Back()).(int)
			leftl[ind] = ind - index - 1
		}
		que.PushBack(index)
		index--
	}
	for que.Len() > 0 {
		ind := que.Remove(que.Back()).(int)
		leftl[ind] = ind - index - 1
	}

	var ans int64 = 0
	for i := 0; i < N; i++ {
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
