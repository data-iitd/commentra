
package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAX = 100005
	N   = 100
)

type P struct {
	name string
	t    int
}

var (
	head int
	tail int
	Q    [MAX + 1]P
)

func Enqueue(x P) {
	if MAX == tail {
		tail = 0
	}
	Q[tail] = x
	tail++
}

func Dequeue() P {
	if head == MAX {
		head = 0
	}
	return Q[head++]
}

func main() {
	var i, q, n, T int
	var a P
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Fscanf(scanner, "%d %d\n", &n, &q)

	for i = 0; i < n; i++ {
		fmt.Fscanf(scanner, "%s%d", &a.name, &a.t)
		Enqueue(a)
	}

	for n!= 0 {
		a = Dequeue()
		if a.t > q {
			a.t = a.t - q
			T = T + q
			Enqueue(a)
		} else {
			T = T + a.t
			fmt.Printf("%s %d\n", a.name, T)
			n--
		}
	}
}

