

package main

import (
    "bufio"
    "fmt"
    "os"
)

type UnionFindTree struct {
    n   int
    par []int
    rank []int
}

func NewUnionFindTree(n int) *UnionFindTree {
    utf := new(UnionFindTree)
    utf.n = n
    utf.par = make([]int, n)
    utf.rank = make([]int, n)
    for i := 0; i < n; i++ {
        utf.par[i] = i
        utf.rank[i] = 0
    }
    return utf
}

func (utf *UnionFindTree) Find(x int) int {
    if utf.par[x] == x {
        return x
    } else {
        utf.par[x] = utf.Find(utf.par[x])
        return utf.par[x]
    }
}

func (utf *UnionFindTree) Unite(x, y int) {
    x = utf.Find(x)
    y = utf.Find(y)
    if x == y {
        return
    }
    if utf.rank[x] < utf.rank[y] {
        utf.par[x] = y
    } else {
        utf.par[y] = x
        if utf.rank[x] == utf.rank[y] {
            utf.rank[x]++
        }
    }
}

func (utf *UnionFindTree) Same(x, y int) bool {
    return utf.Find(x) == utf.Find(y)
}

func main() {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    var n, m int
    fmt.Fscanf(sc, "%d\n", &n)
    utf := NewUnionFindTree(n)
    fmt.Fscanf(sc, "%d\n", &m)
    for i := 0; i < m; i++ {
        var x, y, z int
        fmt.Fscanf(sc, "%d %d %d\n", &x, &y, &z)
        utf.Unite(x-1, y-1)
    }
    cnt := 0
    for i := 0; i < n; i++ {
        if utf.par[i] == i {
            cnt++
        }
    }
    fmt.Println(cnt)
}

