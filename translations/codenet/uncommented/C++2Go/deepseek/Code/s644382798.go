package main

import (
	"fmt"
)

type P struct {
	name [100]byte
	t    int
}

var Q [100005]P
var head, tail, n int

func enqueue(x P) {
	Q[tail] = x
	tail = (tail + 1) % 100005
}

func dequeue() P {
	x := Q[head]
	head = (head + 1) % 100005
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var elaps, c int
	var i int
	var u P

	fmt.Scan(&n, &q)

	for i = 1; i <= n; i++ {
		fmt.Scan(&Q[i].name, &Q[i].t)
	}
	head = 1
	tail = n + 1

	for head != tail {
		u = dequeue()
		c = min(q, u.t)
		u.t -= c
		elaps += c
		if u.t > 0 {
			enqueue(u)
		} else {
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

