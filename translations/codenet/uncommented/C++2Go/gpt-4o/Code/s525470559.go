package main

import (
	"container/list"
	"fmt"
)

type task struct {
	name string
	time int
}

func main() {
	var n, q int
	elaps := 0
	Q := list.New()

	fmt.Scan(&n, &q)

	for i := 0; i < n; i++ {
		var tmp task
		fmt.Scan(&tmp.name, &tmp.time)
		Q.PushBack(tmp)
	}

	for Q.Len() > 0 {
		element := Q.Front()
		p := element.Value.(task)
		Q.Remove(element)

		if p.time <= q {
			elaps += p.time
			fmt.Println(p.name, elaps)
		} else {
			p.time -= q
			elaps += q
			Q.PushBack(p)
		}
	}
}

// <END-OF-CODE>
