
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "container/heap"
)

type pair struct {
    first  int
    second int
}

type pairHeap []pair

func (h pairHeap) Len() int { return len(h) }

func (h pairHeap) Less(i, j int) bool {
    return h[i].first < h[j].first
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
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine()[2:])
    var heap pairHeap
    for i := 0; i < n; i++ {
        num, _ := strconv.Atoi(reader.ReadLine())
        if len(heap) == 0 || heap[0].first < num {
            heap = append(heap, pair{num, 1})
            heapify(&heap, 0)
        } else {
            for len(heap) > 0 && heap[0].first > num {
                heap[0].second += 1
                heapify(&heap, 0)
            }
            if heap[0].first == num {
                heap[0].second += 1
            } else {
                heap = append(heap, pair{num, 1})
            }
        }
    }
    ans := 0
    for i := 0; i < len(heap); i++ {
        ans += heap[i].second
    }
    fmt.Println(ans)
}

func heapify(h *pairHeap, i int) {
    l := 2 * i + 1
    r := 2 * i + 2
    largest := i
    if l < len(*h) && (*h)[l].first > (*h)[largest].first {
        largest = l
    }
    if r < len(*h) && (*h)[r].first > (*h)[largest].first {
        largest = r
    }
    if largest!= i {
        (*h)[i], (*h)[largest] = (*h)[largest], (*h)[i]
        heapify(h, largest)
    }
}

