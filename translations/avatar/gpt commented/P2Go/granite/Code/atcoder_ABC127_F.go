
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"container/heap"
)

type IntHeap []int

func (h IntHeap) Len() int { return len(h) }

func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }

func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func main() {
	data := bufio.NewReader(os.Stdin)
	q, _ := strconv.Atoi(read(data))
	ans := make([]int, 2)
	p1 := &IntHeap{}
	p2 := &IntHeap{}
	heap.Init(p1)
	heap.Init(p2)
	sum_b := 0
	sum_p1 := 0
	sum_p2 := 0
	for i := 0; i < q; i++ {
		ql := readi(data)
		if ql[0] == 2 {
			if len(*p1) == len(*p2) {
				ans[i%2] = -(*p2)[0] + sum_p1 - len(*p1)*-(*p2)[0] + len(*p2)*-(*p2)[0] - sum_p2 + sum_b
			} else {
				ans[i%2] = (*p1)[0] + sum_p1 - len(*p1)*(*p1)[0] + len(*p2)*(*p1)[0] - sum_p2 + sum_b
			}
		} else {
			sum_b += ql[2]
			if len(*p1) == 0 {
				heap.Push(p1, ql[1])
				sum_p1 += ql[1]
			} else if (*p1)[0] <= ql[1] {
				heap.Push(p1, ql[1])
				sum_p1 += ql[1]
			} else {
				heap.Push(p2, -ql[1])
				sum_p2 += ql[1]
			}
			if len(*p1) < len(*p2) {
				k := heap.Pop(p2).(int)
				heap.Push(p1, -k)
				sum_p2 -= k
				sum_p1 += k
			}
			if len(*p1)-1 > len(*p2) {
				k := heap.Pop(p1).(int)
				heap.Push(p2, -k)
				sum_p1 -= k
				sum_p2 += k
			}
		}
	}
	for _, v := range ans {
		fmt.Println(v)
	}
}

func read(data *bufio.Reader) string {
	r, _, _ := data.ReadLine()
	return string(r)
}

func readi(data *bufio.Reader) []int {
	r, _, _ := data.ReadLine()
	i, _ := strconv.Atoi(string(r))
	return []int{i}
}

func readis(data *bufio.Reader) []int {
	r, _, _ := data.ReadLine()
	x := []int{}
	for _, num := range strings.Split(string(r), " ") {
		i, _ := strconv.Atoi(num)
		x = append(x, i)
	}
	return x
}

func readf(data *bufio.Reader) float64 {
	r, _, _ := data.ReadLine()
	f, _ := strconv.ParseFloat(string(r), 64)
	return f
}

func readfs(data *bufio.Reader) []float64 {
	r, _, _ := data.ReadLine()
	x := []float64{}
	for _, num := range strings.Split(string(r), " ") {
		f, _ := strconv.ParseFloat(num, 64)
		x = append(x, f)
	}
	return x
}

func reads(data *bufio.Reader) string {
	r, _, _ := data.ReadLine()
	return string(r)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func pow(a, b int) int {
	result := 1
	for i := 0; i < b; i++ {
		result *= a
	}
	return result
}

func abs(a int) int {
	return max(a, -a)
}

func all(a bool) bool {
	return a
}

func any(a bool) bool {
	return a
}

func perr(v...interface{}) {
	fmt.Fprintln(os.Stderr, v...)
}

func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func reverse_r(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func min_i(a []int) int {
	min_v := a[0]
	for _, v := range a {
		if v < min_v {
			min_v = v
		}
	}
	return min_v
}

func max_i(a []int) int {
	max_v := a[0]
	for _, v := range a {
		if v > max_v {
			max_v = v
		}
	}
	return max_v
}

func sum_i(a []int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

func argsort(a []int) []int {
	b := make([]int, len(a))
	copy(b, a)
	sort.Ints(b)
	return b
}

func f_to_i(a []float64) []int {
	b := make([]int, len(a))
	for i, v := range a {
		b[i] = int(v)
	}
	return b
}

func i_to_f(a []int) []float64 {
	b := make([]float64, len(a))
	for i, v := range a {
		b[i] = float64(v)
	}
	return b
}

func bool_to_i(a []bool) []int {
	b := make([]int, len(a))
	for i, v := range a {
		if v {
			b[i] = 1
		} else {
			b[i] = 0
		}
	}
	return b
}

func i_to_bool(a []int) []bool {
	b := make([]bool, len(a))
	for i, v := range a {
		if v == 1 {
			b[i] = true
		} else {
			b[i] = false
		}
	}
	return b
}

func main_test() {
	fmt.Println("Hello World!")
}