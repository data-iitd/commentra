package main

import (
	"fmt"
)

const (
	MAX  = 100005
	N    = 100
)

type Process struct {
	name [N]byte
	t    int
}

var (
	Q      [MAX + 1]Process
	head   int
	tail   int
)

func Enqueue(x Process) {
	if tail == MAX {
		tail = 0
	}
	Q[tail] = x
	tail++
}

func Dequeue() Process {
	if head == MAX {
		head = 0
	}
	process := Q[head]
	head++
	return process
}

func main() {
	var i, q, n, T int
	var a Process

	fmt.Scan(&n, &q)

	for i = 0; i < n; i++ {
		fmt.Scan(&a.name, &a.t)
		Enqueue(a)
	}

	for n != 0 {
		a = Dequeue()
		if a.t > q {
			a.t -= q
			T += q
			Enqueue(a)
		} else {
			T += a.t
			fmt.Printf("%s %d\n", a.name, T)
			n--
		}
	}
}

