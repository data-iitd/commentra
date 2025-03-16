package main
import "container/heap"
import "fmt"
type Item struct {
    day int
    salary int
}
type PriorityQueue []*Item
func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i].day < pq[j].day
}
func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PriorityQueue) Push(x interface{}) {
    item := x.(*Item)
    *pq = append(*pq, item)
}
func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    *pq = old[0 : n-1]
    return item
}
func main() {
    n, m := 0, 0
    x := make(PriorityQueue, 0)
    y := make(PriorityQueue, 0)
    fmt.Scanf("%d %d", &n, &m)
    for i := 0; i < n; i++ {
        var day, salary int
        fmt.Scanf("%d %d", &day, &salary)
        heap.Push(&x, &Item{day: -day, salary: -salary})
    }
    for x.Len() > 0 {
        d, s := heap.Pop(&x).(*Item)
        r := m - y.Len()
        if r >= -d.day {
            heap.Push(&y, &Item{day: -s.salary})
        } else {
            heap.Push(&y, &Item{day: -s.salary})
            heap.Pop(&y)
        }
    }
    fmt.Printf("%d\n", sum(y))
}

