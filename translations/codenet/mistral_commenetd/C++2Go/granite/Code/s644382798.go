

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Process struct {
	name string
	t    int // time taken by each process
}

var (
	q     int // number of units processed in each iteration
	n     int // total number of processes
	head  int // head index of the queue
	tail  int // tail index of the queue
	queue [100005]Process
	elaps int // elapsed time
)

func enqueue(p Process) {
	queue[tail] = p
	tail = (tail + 1) % 100005
}

func dequeue() Process {
	p := queue[head]
	head = (head + 1) % 100005
	return p
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d", &n, &q)

	for i := 1; i <= n; i++ {
		var name string
		var t int
		fmt.Fscanf(reader, "%s", &name)
		fmt.Fscanf(reader, "%d", &t)
		enqueue(Process{name, t})
	}
	head = 1
	tail = n + 1

	for head!= tail {
		p := dequeue()
		c := min(q, p.t)
		p.t -= c
		elaps += c
		if p.t > 0 {
			enqueue(p)
		} else {
			fmt.Printf("%s %d\n", p.name, elaps)
		}
	}
}

