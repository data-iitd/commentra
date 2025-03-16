
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
	var n, q int
	var elaps int = 0
	var Q []task
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &n, &q)
	for i := 0; i < n; i++ {
		tmp := task{}
		fmt.Fscanf(reader, "%s %d\n", &tmp.name, &tmp.time)
		Q = append(Q, tmp)
	}
	for len(Q) > 0 {
		p := Q[0]
		Q = Q[1:]
		if p.time <= q {
			elaps += p.time
			fmt.Printf("%s %d\n", p.name, elaps)
		} else {
			p.time -= q
			elaps += q
			Q = append(Q, p)
		}
	}
}

