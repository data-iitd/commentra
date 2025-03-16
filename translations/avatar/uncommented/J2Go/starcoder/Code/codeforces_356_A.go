package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type TreeSet struct {
	data []int
}

func (t *TreeSet) add(val int) {
	t.data = append(t.data, val)
}

func (t *TreeSet) remove(val int) {
	for i := 0; i < len(t.data); i++ {
		if t.data[i] == val {
			t.data = append(t.data[:i], t.data[i+1:]...)
			return
		}
	}
}

func (t *TreeSet) ceiling(val int) *int {
	for i := 0; i < len(t.data); i++ {
		if t.data[i] >= val {
			return &t.data[i]
		}
	}
	return nil
}

func main() {
	in := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(in))
	left := TreeSet{}
	for i := 0; i < n; i++ {
		left.add(i)
	}
	q, _ := strconv.Atoi(readLine(in))
	for q > 0 {
		l, _ := strconv.Atoi(readLine(in))
		r, _ := strconv.Atoi(readLine(in))
		win, _ := strconv.Atoi(readLine(in))
		for left.ceiling(l)!= nil && *left.ceiling(l) <= r {
			curr := *left.ceiling(l)
			left.remove(curr)
			answer[curr] = win
			left.add(win - 1)
		}
		answer[win-1] = 0
		q--
	}
	ans := ""
	for i := 0; i < n; i++ {
		ans += fmt.Sprintf("%d", answer[i])
	}
	fmt.Println(ans)
}

func readLine(in *bufio.Reader) string {
	buf := make([]byte, 0, 1024)
	for {
		line, isPrefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if!isPrefix {
			break
		}
	}
	return strings.TrimSpace(string(buf))
}

