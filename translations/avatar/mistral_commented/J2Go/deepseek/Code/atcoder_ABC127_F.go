package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var out = bufio.NewWriter(os.Stdout)

func main() {
	br := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(br, &t)

	var s []string
	pqmax := &PriorityQueue{less: func(i, j int) bool { return pqmax.data[i] > pqmax.data[j] }}
	pqmin := &PriorityQueue{less: func(i, j int) bool { return pqmin.data[i] < pqmin.data[j] }}
	var sumMin, sumMax, sumb int64
	var min int

	for t > 0 {
		t--
		s = nil
		s, _ = bufio.NewReader(os.Stdin).ReadString('\n')
		s = s[:len(s)-1]
		fields := strings.Fields(s)

		if fields[0] == "2" {
			ans := int64(min) * int64(pqmin.Len())
			ans -= sumMin
			ans1 := int64(min) * int64(pqmax.Len())
			ans1 -= sumMax
			fmt.Fprintln(out, min, ans+ans1+sumb)
		} else {
			in := parseInt(fields[1])
			sumb += parseInt(fields[2])

			if in > min {
				pqmax.Push(in)
				sumMax += int64(in)
			} else {
				pqmin.Push(in)
				sumMin += int64(in)
			}

			if pqmin.Len() > pqmax.Len() {
				sumMax += int64(pqmin.data[0])
				sumMin -= int64(pqmin.data[0])
				pqmax.Push(pqmin.Pop())
			} else if pqmin.Len() < pqmax.Len() {
				sumMax -= int64(pqmax.data[0])
				sumMin += int64(pqmax.data[0])
				pqmin.Push(pqmax.Pop())
			}

			min = pqmin.data[0]
		}
	}

	out.Flush()
}

type PriorityQueue struct {
	data []int
	less func(i, j int) bool
}

func (pq *PriorityQueue) Push(x int) {
	pq.data = append(pq.data, x)
	pq.up(len(pq.data) - 1)
}

func (pq *PriorityQueue) Pop() int {
	n := len(pq.data)
	x := pq.data[0]
	pq.data[0] = pq.data[n-1]
	pq.data = pq.data[:n-1]
	pq.down(0)
	return x
}

func (pq *PriorityQueue) up(j int) {
	for {
		i := (j - 1) / 2
		if i == j || !pq.less(j, i) {
			break
		}
		pq.data[i], pq.data[j] = pq.data[j], pq.data[i]
		j = i
	}
}

func (pq *PriorityQueue) down(i int) {
	n := len(pq.data)
	for {
		j1 := 2*i + 1
		if j1 >= n || j1 < 0 {
			break
		}
		j := j1
		if j2 := j1 + 1; j2 < n && pq.less(j2, j1) {
			j = j2
		}
		if !pq.less(j, i) {
			break
		}
		pq.data[i], pq.data[j] = pq.data[j], pq.data[i]
		i = j
	}
}

func (pq *PriorityQueue) Len() int {
	return len(pq.data)
}

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}
