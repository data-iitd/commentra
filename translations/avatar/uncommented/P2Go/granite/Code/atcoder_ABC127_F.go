
package main

import (
    "bufio"
    "container/heap"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type pair struct {
    a, b int
}

type pairHeap []pair

func (h pairHeap) Len() int { return len(h) }

func (h pairHeap) Less(i, j int) bool {
    return h[i].a < h[j].a
}

func (h pairHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

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
    var q int
    fmt.Fscan(scanner, &q)
    sumB := 0
    sumP1 := 0
    sumP2 := 0
    p1 := make(pairHeap, 0, initialSize)
    p2 := make(pairHeap, 0, initialSize)
    heap.Init(&p1)
    heap.Init(&p2)
    for i := 0; i < q; i++ {
        var t int
        fmt.Fscan(scanner, &t)
        if t == 1 {
            var a, b int
            fmt.Fscan(scanner, &a, &b)
            sumB += b
            if len(p1) == 0 {
                heap.Push(&p1, pair{a, b})
                sumP1 += a
            } else if p1[0].a <= a {
                heap.Push(&p1, pair{a, b})
                sumP1 += a
            } else {
                heap.Push(&p2, pair{-a, b})
                sumP2 += a
            }
            if len(p1) < len(p2) {
                p := heap.Pop(&p2)
                pairP := p.(pair)
                pairP.a = -pairP.a
                heap.Push(&p1, pairP)
                sumP2 -= pairP.a
                sumP1 += pairP.a
            }
            if len(p1) > len(p2)+1 {
                p := heap.Pop(&p1)
                pairP := p.(pair)
                pairP.a = -pairP.a
                heap.Push(&p2, pairP)
                sumP1 -= pairP.a
                sumP2 += pairP.a
            }
        } else {
            if len(p1) == len(p2) {
                fmt.Printf("%d %d\n", p1[0].a, sumP1-len(p1)*p1[0].a+len(p2)*p1[0].a-sumP2+sumB)
            } else {
                fmt.Printf("%d %d\n", -p2[0].a, sumP1-len(p1)*p2[0].a+len(p2)*p2[0].a-sumP2+sumB)
            }
        }
    }
}
