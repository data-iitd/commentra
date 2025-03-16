

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
    "container/heap"
    "container/list"
)

type pair struct {
    first, second int
}

type pairList []pair

func (p pairList) Len() int { return len(p) }

func (p pairList) Less(i, j int) bool {
    if p[i].first == p[j].first {
        return p[i].second < p[j].second
    }
    return p[i].first > p[j].first
}

func (p pairList) Swap(i, j int) { p[i], p[j] = p[j], p[i] }

func (p *pairList) Push(x interface{}) {
    *p = append(*p, x.(pair))
}

func (p *pairList) Pop() interface{} {
    old := *p
    n := len(old)
    x := old[n-1]
    *p = old[0 : n-1]
    return x
}

func main() {
    n, a := read()
    s := make(pairList, 0)
    heap.Init(&s)
    ng := 0
    ok := n
    for ok-ng > 1 {
        k := (ng + ok) / 2
        if isPossible(k, n, a) {
            ok = k
        } else {
            ng = k
        }
    }
    fmt.Println(ok)
}

func read() (int, []int) {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(readOneLine(reader))
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(readOneLine(reader)))
    }
    return n, a
}

func readOneLine(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    return strings.TrimSpace(s)
}

func isPossible(k int, n int, a []int) bool {
    s := make(pairList, 0)
    heap.Init(&s)
    current := 0
    for i := 0; i < n; i++ {
        if a[i] <= current {
            if k == 1 {
                return false
            }
            for s.Len() > 0 && s[0].first >= a[i] {
                heap.Pop(&s)
            }
            p := a[i] - 1
            for {
                if p < 0 {
                    return false
                }
                sp := 0
                for s.Len() > 0 && s[0].first == p {
                    sp += s[0].second
                    heap.Pop(&s)
                }
                sp++
                if sp == k {
                    break
                }
                heap.Push(&s, pair{p, sp})
                p--
            }
        }
        current = a[i]
    }
    return true
}

