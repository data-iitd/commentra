package main

import (
	"fmt"
	"container/list"
)

func main() {
	var n, b int
	fmt.Scan(&n, &b)
	ans := make([]int64, n)
	q := list.New()
	for i := 0; i < n; i++ {
		var t, d int
		fmt.Scan(&t, &d)
		for q.Len() > 0 && q.Front().Value.(int64) <= int64(t) {
			q.Remove(q.Front())
		}
		if q.Len() <= b {
			if q.Len() == 0 {
				ans[i] = int64(t) + int64(d)
			} else {
				ans[i] = q.Back().Value.(int64) + int64(d)
			}
			q.PushBack(ans[i])
		} else {
			ans[i] = -1
		}
	}
	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
}

