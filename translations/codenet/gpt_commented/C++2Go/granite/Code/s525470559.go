
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
	var n, q int
	fmt.Fscanf(reader, "%d %d\n", &n, &q)
	var elaps int
	tasks := make([]task, n)
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		fields := strings.Fields(line)
		tasks[i] = task{fields[0], mustParseInt(fields[1])}
	}
	for len(tasks) > 0 {
		p := tasks[0]
		tasks = tasks[1:]
		if p.time <= q {
			elaps += p.time
			fmt.Printf("%s %d\n", p.name, elaps)
		} else {
			p.time -= q
			elaps += q
			tasks = append(tasks, p)
		}
	}
}

func mustParseInt(s string) int {
	i, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return i
}

