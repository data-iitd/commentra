package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var outputStream = os.Stdout
var out = bufio.NewWriter(outputStream)

func main() {
	br := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(br, &t)
	pqmax := &PriorityQueue{less: func(i, j int) bool { return pq[i] < pq[j] }}
	pqmin := &PriorityQueue{less: func(i, j int) bool { return pq[i] > pq[j] }}
	var sumMin, sumMax, sumb int64
	var min int
	for t > 0 {
		t--
		var s []string
		s, _ = br.ReadString(' ')
		s = s[:len(s)-1]
		if s[0] == '2' {
			ans := int64(min)
			ans *= int64(pqmin.Len())
			ans -= sumMin
			ans1 := int64(min)
			ans1 *= int64(pqmax.Len())
			ans1 = sumMax - ans1
			fmt.Fprintln(out, min, ans+ans1+sumb)
		} else {
			var in int
			var inStr string
			fmt.Fscan(br, &inStr)
			fmt.Fscan(br, &in)
			sumb += int64(in)
			if in > min {
				pqmax.Push(in)
				sumMax += int64(in)
			} else {
				pqmin.Push(in)
				sumMin += int64(in)
			}
			if pqmin.Len() > pqmax.Len() {
				sumMax += int64(pqmin.Peek())
				sumMin -= int64(pqmin.Peek())
				pqmax.Push(pqmin.Pop())
			}
			if pqmin.Len() < pqmax.Len() {
				sumMax -= int64(pqmax.Peek())
				sumMin += int64(pqmax.Peek())
				pqmin.Push(pqmax.Pop())
			}
			min = pqmin.Peek()
		}
	}
	out.Flush()
}

type PriorityQueue struct {
	pq   []int
	less func(i, j int) bool
}

func (pq *PriorityQueue) Push(x int) {
	pq.pq = append(pq.pq, x)
	pq.up(len(pq.pq) - 1)
}

func (pq *PriorityQueue) Pop() int {
	n := len(pq.pq)
	x := pq.pq[0]
	pq.pq[0] = pq.pq[n-1]
	pq.pq = pq.pq[:n-1]
	pq.down(0)
	return x
}

func (pq *PriorityQueue) Peek() int {
	return pq.pq[0]
}

func (pq *PriorityQueue) Len() int {
	return len(pq.pq)
}

func (pq *PriorityQueue) up(i int) {
	for {
		parent := (i - 1) / 2
		if parent == i || !pq.less(i, parent) {
			break
		}
		pq.pq[i], pq.pq[parent] = pq.pq[parent], pq.pq[i]
		i = parent
	}
}

func (pq *PriorityQueue) down(i int) {
	n := len(pq.pq)
	for {
		left := 2*i + 1
		right := 2*i + 2
		smallest := i
		if left < n && pq.less(left, smallest) {
			smallest = left
		}
		if right < n && pq.less(right, smallest) {
			smallest = right
		}
		if smallest == i {
			break
		}
		pq.pq[i], pq.pq[smallest] = pq.pq[smallest], pq.pq[i]
		i = smallest
	}
}

