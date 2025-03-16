package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type task struct {
	name string
	time int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &q)

	var Q []task
	elaps := 0

	for i := 0; i < n; i++ {
		var tmp task
		fmt.Fscan(reader, &tmp.name, &tmp.time)
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

