package main
import "fmt"
import "container/heap"
type IntHeap []int
func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x interface{}) { *h = append(*h, x.(int)) }
func (h *IntHeap) Pop() interface{}   { old := *h; n := len(old); x := old[n-1]; *h = old[0 : n-1]; return x }
func main() {
	var q int
	fmt.Scanf("%d", &q)
	ans := [2]int{0, 0}
	p1 := &IntHeap{}
	p2 := &IntHeap{}
	heap.Init(p1)
	heap.Init(p2)
	sum_b := 0
	sum_p1 := 0
	sum_p2 := 0
	for i := 0; i < q; i++ {
		var ql []int
		fmt.Scanf("%d %d %d", &ql[0], &ql[1], &ql[2])
		if ql[0] == 2 {
			if len(*p1) == len(*p2) {
				fmt.Printf("%d %d\n", -(*p2)[0], sum_p1-len(*p1)*-(*p2)[0]+len(*p2)*-(*p2)[0]-sum_p2+sum_b)
			} else {
				fmt.Printf("%d %d\n", (*p1)[0], sum_p1-len(*p1)*(*p1)[0]+len(*p2)*(*p1)[0]-sum_p2+sum_b)
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
				sum_p2 += k
				sum_p1 -= k
			}
			if len(*p1)-1 > len(*p2) {
				k := heap.Pop(p1).(int)
				heap.Push(p2, -k)
				sum_p1 -= k
				sum_p2 += k
		}
	}
}
