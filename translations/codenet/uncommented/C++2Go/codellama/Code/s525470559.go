package main

import (
	"fmt"
	"os"
)

type task struct {
	name string
	time int
}

func main() {
	var n, q int
	var elaps int
	var Q []task

	fmt.Scan(&n, &q)

	for i := 0; i < n; i++ {
		var tmp task
		fmt.Scan(&tmp.name, &tmp.time)
		Q = append(Q, tmp)
	}

	for len(Q) > 0 {
		p := Q[0]
		Q = Q[1:]
		if p.time <= q {
			elaps += p.time
			fmt.Println(p.name, elaps)
		} else {
			p.time -= q
			elaps += q
			Q = append(Q, p)
		}
	}
}

