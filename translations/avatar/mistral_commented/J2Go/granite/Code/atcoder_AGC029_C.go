

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
 "strings"
 "container/heap"
)

type pair struct {
 key   int
 value int
}

type pairHeap []pair

func (h pairHeap) Len() int { return len(h) }

func (h pairHeap) Less(i, j int) bool { return h[i].key < h[j].key }

func (h pairHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *pairHeap) Push(x interface{}) { *h = append(*h, x.(pair)) }

func (h *pairHeap) Pop() interface{} {
 old := *h
 n := len(old)
 x := old[n-1]
 *h = old[0 : n-1]
 return x
}

func main() {
 var n int
 var a []int
 var s pairHeap

 reader := bufio.NewReader(os.Stdin)
 line, _ := reader.ReadString('\n')
 n, _ = strconv.Atoi(strings.TrimSpace(line))
 line, _ = reader.ReadString('\n')
 a = make([]int, n)
 for i, v := range strings.Split(strings.TrimSpace(line), " ") {
 a[i], _ = strconv.Atoi(v)
 }
 ng := 0
 ok := n
 for ok-ng > 1 {
 k := (ng + ok) / 2
 if isPossible(k, a, &s) {
 ok = k
 } else {
 ng = k
 }
 }
 fmt.Println(ok)
}

func isPossible(k int, a []int, s *pairHeap) bool {
 *s = (*s)[0:0]
 current := 0
 for _, ai := range a {
 if ai <= current {
 if k == 1 {
 return false
 }
 for len(*s) > 0 && (*s)[len(*s)-1].key >= ai {
 heap.Pop(s)
 }
 p := ai - 1
 for {
 if p < 0 {
 return false
 }
 sp := 0
 for len(*s) > 0 && (*s)[len(*s)-1].key == p {
 sp += (*s)[len(*s)-1].value
 heap.Pop(s)
 }
 sp++
 if sp == k {
 heap.Push(s, pair{p, sp})
 p--
 } else {
 break
 }
 }
 }
 current = ai
 }
 return true
}

These comments should provide a clear understanding of the code logic and flow. Let me know if you need any further assistance.