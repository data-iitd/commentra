package main

import (
	"fmt"
)

const LEN = 100005

type P struct {
	name string
	t    int
}

var Q [LEN]P
var head, tail, n int

func enqueue(x P) {
	Q[tail] = x
	tail = (tail + 1) % LEN
}

func dequeue() P {
	x := Q[head]
	head = (head + 1) % LEN
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
	var u P
	var q int

	fmt.Scan(&n, &q)

	for i := 1; i <= n; i++ {
		fmt.Scan(&Q[i].name)
		fmt.Scan(&Q[i].t)
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

// <END-OF-CODE>
