
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	q, _ := strconv.Atoi(read(reader))
	ans := []int{0, 0}
	p1 := make([]int, 0)
	p2 := make([]int, 0)
	sumB := 0
	sumP1 := 0
	sumP2 := 0

	for i := 0; i < q; i++ {
		ql := readLine(reader)
		qls := split(ql)
		qt, _ := strconv.Atoi(qls[0])
		if qt == 2 {
			if len(p1) == len(p2) {
				fmt.Printf("%d %d\n", -p2[0], sumP1-len(p1)*-p2[0]+len(p2)*-p2[0]-sumP2+sumB)
			} else {
				fmt.Printf("%d %d\n", p1[0], sumP1-len(p1)*p1[0]+len(p2)*p1[0]-sumP2+sumB)
			}
		} else {
			sumB += int(mustParseInt(qls[2]))
			if len(p1) == 0 {
				p1 = append(p1, mustParseInt(qls[1]))
				sumP1 += mustParseInt(qls[1])
			} else if p1[0] <= mustParseInt(qls[1]) {
				p1 = append(p1, mustParseInt(qls[1]))
				sumP1 += mustParseInt(qls[1])
			} else {
				p2 = append(p2, -mustParseInt(qls[1]))
				sumP2 += mustParseInt(qls[1])
			}
			if len(p1) < len(p2) {
				k := heapPop(p2)
				p1 = append(p1, -k)
				sumP2 += k
				sumP1 -= k
			}
			if len(p1)-1 > len(p2) {
				k := heapPop(p1)
				p2 = append(p2, -k)
				sumP1 -= k
				sumP2 += k
			}
		}
	}
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func readLine(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	return s
}

func split(s string) []string {
	return strings.Split(s, " ")
}

func mustParseInt(s string) int {
	n, _ := strconv.Atoi(s)
	return n
}

func heapPop(h []int) int {
	h[0], h[len(h)-1] = h[len(h)-1], h[0]
	poped := h[len(h)-1]
	h = h[:len(h)-1]
	fixHeap(h, 0)
	return poped
}

func fixHeap(h []int, i int) {
	l := i * 2 + 1
	r := i * 2 + 2
	largest := i
	if l < len(h) && h[l] > h[largest] {
		largest = l
	}
	if r < len(h) && h[r] > h[largest] {
		largest = r
	}
	if largest!= i {
		h[i], h[largest] = h[largest], h[i]
		fixHeap(h, largest)
	}
}

