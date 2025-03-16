package main

import (
	"fmt"
)

const (
	MAX = 100005
	N   = 100
)

type P struct {
	name [N]byte
	t    int
}

var (
	Q      [MAX + 1]P
	head   int
	tail   int
)

func Enqueue(x P) {
	if tail == MAX {
		tail = 0
	}
	Q[tail] = x
	tail++
}

func Dequeue() P {
	var temp P
	if head == MAX {
		head = 0
	}
	temp = Q[head]
	head++
	return temp
}

func main() {
	var (
		i, q, n int
		a       P
		T       int
	)

	fmt.Scan(&n, &q)

	for i = 0; i < n; i++ {
		fmt.Scan(&a.name, &a.t)
		Enqueue(a)
	}

	for n != 0 {
		a = Dequeue()
		if a.t > q {
			a.t = a.t - q
			T += q
			Enqueue(a)
		} else {
			T += a.t
			fmt.Printf("%s %d\n", a.name, T)
			n--
		}
	}
}

