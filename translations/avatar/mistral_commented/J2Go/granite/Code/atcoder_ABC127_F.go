

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "container/heap"
)

type MinHeap []int

func (h MinHeap) Len() int { return len(h) }

func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }

func (h MinHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

type MaxHeap []int

func (h MaxHeap) Len() int { return len(h) }

func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }

func (h MaxHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    var t int
    fmt.Fscanf(reader, "%d\n", &t)

    var sumb int64
    var min int
    pqmin := &MinHeap{}
    pqmax := &MaxHeap{}

    for t > 0 {
        var op string
        var in int
        var ans int64

        fmt.Fscanf(reader, "%s", &op)

        if op[0] == '2' {
            ans = int64(min) * int64(len(*pqmin))
            ans -= sumb
            ans1 := int64(min) * int64(len(*pqmax))
            ans1 = sumb - ans1
            fmt.Fprintf(writer, "%d %d\n", min, ans+ans1)
        } else {
            fmt.Fscanf(reader, "%d %d\n", &in, &in)
            sumb += int64(in)

            if in > min {
                heap.Push(pqmax, in)
                sumb += int64(in)
            } else {
                heap.Push(pqmin, in)
                sumb -= int64(in)
            }

            if len(*pqmin) > len(*pqmax) {
                x := heap.Pop(pqmin)
                heap.Push(pqmax, x.(int))
                sumb += int64(x.(int))
            } else if len(*pqmin) < len(*pqmax) {
                x := heap.Pop(pqmax)
                heap.Push(pqmin, x.(int))
                sumb -= int64(x.(int))
            }

            min = (*pqmin)[0]
        }

        t--
    }

    writer.Flush()
}

