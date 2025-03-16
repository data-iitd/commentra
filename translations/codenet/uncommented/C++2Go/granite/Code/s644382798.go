
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pp struct {
	name string
	t    int
}

var (
	q     int
	n     int
	head  int
	tail  int
	Q     [100005]pp
	elaps int
)

func enqueue(x pp) {
	Q[tail] = x
	tail = (tail + 1) % 100005
}

func dequeue() pp {
	x := Q[head]
	head = (head + 1) % 100005
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		text := scanner.Text()
		if text == "" {
			break
		}
		sp := strings.Split(text, " ")
		Q[n+1].name = sp[0]
		Q[n+1].t, _ = strconv.Atoi(sp[1])
		n++
	}
	head = 1
	tail = n + 1
	for head!= tail {
		u := dequeue()
		c := min(q, u.t)
		u.t -= c
		elaps += c
		if u.t > 0 {
			enqueue(u)
		} else {
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

