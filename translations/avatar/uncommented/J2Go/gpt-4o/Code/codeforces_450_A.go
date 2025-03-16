package main

import (
	"container/list"
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	q1 := list.New()
	q2 := list.New()

	for i := 1; i <= n; i++ {
		var value int
		fmt.Scan(&value)
		q1.PushBack(value)
		q2.PushBack(i)
	}

	var ans int
	for q1.Len() > 0 {
		front1 := q1.Front()
		if front1.Value.(int) <= m {
			ans = q2.Front().Value.(int)
			q1.Remove(front1)
			q2.Remove(q2.Front())
		} else {
			x := front1.Value.(int)
			q1.Remove(front1)
			val := x - m
			q1.PushBack(val)
			val2 := q2.Front()
			q2.Remove(val2)
			q2.PushBack(val2.Value)
		}
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
