package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Task struct {
	Name string
	Time int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	inputs := strings.Fields(scanner.Text())
	n, _ := strconv.Atoi(inputs[0])
	q, _ := strconv.Atoi(inputs[1])

	var Q []Task
	elaps := 0

	for i := 0; i < n; i++ {
		scanner.Scan()
		fields := strings.Fields(scanner.Text())
		time, _ := strconv.Atoi(fields[1])
		task := Task{fields[0], time}
		Q = append(Q, task)
	}

	for len(Q) > 0 {
		p := Q[0]
		Q = Q[1:]
		if p.Time <= q {
			elaps += p.Time
			fmt.Println(p.Name, elaps)
		} else {
			p.Time -= q
			elaps += q
			Q = append(Q, p)
		}
	}
}

