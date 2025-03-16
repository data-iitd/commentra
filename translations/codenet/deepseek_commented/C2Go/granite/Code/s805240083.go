
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	Q     [MAX + 1]P
	head  int
	tail  int
)

func Enqueue(x P) {
	if MAX == tail {
		tail = 0
	}
	Q[tail] = x
	tail++
}

func Dequeue() P {
	if MAX == head {
		head = 0
	}
	x := Q[head]
	head++
	return x
}

func main() {
	var (
		i, q, n, T int
		a           P
		sc          = bufio.NewScanner(os.Stdin)
	)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	q, _ = strconv.Atoi(sc.Text())
	for i = 0; i < n; i++ {
		sc.Scan()
		a.name = sc.Text()
		sc.Scan()
		a.t, _ = strconv.Atoi(sc.Text())
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

