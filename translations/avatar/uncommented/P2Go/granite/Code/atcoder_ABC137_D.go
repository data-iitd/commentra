
package main

import (
    "bufio"
    "container/heap"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

type pair struct {
    day, salary int
}

type pairHeap []pair

func (h pairHeap) Len() int { return len(h) }

func (h pairHeap) Less(i, j int) bool {
    if h[i].day == h[j].day {
        return h[i].salary > h[j].salary
    }
    return h[i].day < h[j].day
}

func (h pairHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *pairHeap) Push(x interface{}) {
    *h = append(*h, x.(pair))
}

func (h *pairHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const initialSize = 400000
    var n, m int
    fmt.Fscanf(scanner, "%d %d\n", &n, &m)
    h := make(pairHeap, 0, initialSize)
    for i := 0; i < n; i++ {
        var day, salary int
        fmt.Fscanf(scanner, "%d %d\n", &day, &salary)
        h = append(h, pair{day, salary})
    }
    sort.Sort(sort.Reverse(h))
    heap.Init(&h)
    for h.Len() > m {
        heap.Pop(&h)
    }
    sum := 0
    for h.Len() > 0 {
        sum += heap.Pop(&h).(pair).salary
    }
    fmt.Println(sum)
}

