
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type P struct {
	name string
	t    int
}

const LEN = 100005

var (
	head, tail, n, elaps, c, i, q int
	Q                                 [LEN]P
)

func enqueue(x P) {
	Q[tail] = x
	tail = (tail + 1) % LEN
}

func dequeue() P {
	x := Q[head]
	head = (head + 1) % LEN
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
		Q[i+1].name = sp[0]
		Q[i+1].t, _ = strconv.Atoi(sp[1])
		i++
	}
	head = 1
	tail = n + 1
	for head!= tail {
		u := dequeue()
		c = min(q, u.t)
		u.t -= c
		elaps += c
		if u.t > 0 {
			enqueue(u)
		} else {
			fmt.Printf("%s %d\n", u.name, elaps)
		}
	}
}

