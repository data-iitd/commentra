
package main

import (
    "bufio"
    "container/heap"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type item struct {
    degree int
    index  int
}

type itemHeap []item

func (h itemHeap) Len() int { return len(h) }

func (h itemHeap) Less(i, j int) bool {
    if h[i].degree == h[j].degree {
        return h[i].index < h[j].index
    }
    return h[i].degree < h[j].degree
}

func (h itemHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *itemHeap) Push(x interface{}) {
    *h = append(*h, x.(item))
}

func (h *itemHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

func main() {
    data := bufio.NewScanner(os.Stdin)
    data.Split(bufio.ScanWords)
    N, M := nextInt(data), nextInt(data)
    edges := make([][]int, N)
    degs := make([]int, N)
    parity := make([]int, N)
    flag := make([]bool, N)
    for i := 0; i < N; i++ {
        edges[i] = make([]int, 0)
    }
    for i := 0; i < M; i++ {
        a, b := nextInt(data), nextInt(data)
        a--
        b--
        edges[a] = append(edges[a], b)
        edges[b] = append(edges[b], a)
        degs[a]++
        degs[b]++
    }
    if M%2!= 0 {
        fmt.Println(-1)
        return
    }
    Q := &itemHeap{}
    heap.Init(Q)
    for i := 0; i < N; i++ {
        heap.Push(Q, item{degs[i], i})
    }
    for len(*Q) > 0 {
        item := heap.Pop(Q).(*item)
        if flag[item.index] {
            continue
        }
        flag[item.index] = true
        for i, v := range edges[item.index] {
            edges[v] = remove(edges[v], item.index)
            if parity[item.index]!= 0 && i == 0 {
                fmt.Printf("%d %d\n", item.index+1, v+1)
                parity[item.index] = 1 - parity[item.index]
            } else {
                fmt.Printf("%d %d\n", v+1, item.index+1)
                parity[v] = 1 - parity[v]
            }
            degs[v]--
            heap.Push(Q, item{degs[v], v})
        }
    }
}

func nextInt(data *bufio.Scanner) int {
    data.Scan()
    x, _ := strconv.Atoi(data.Text())
    return x
}

func remove(s []int, x int) []int {
    for i, v := range s {
        if v == x {
            return append(s[:i], s[i+1:]...)
        }
    }
    return s
}

