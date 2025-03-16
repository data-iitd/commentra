#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

type i32 int32
type i64 int64

type directedEdge struct {
  vertex i32
  next i32
}

type directedGraph struct {
  edge []directedEdge
  start []i32
  pointer i32
  vertexNum i32
  edgeMaxSize i32
}

func newGraph(vertexNum i32) *directedGraph {
  g := &directedGraph{}
  g.edge = make([]directedEdge, 1)
  g.start = make([]i32, vertexNum)
  g.pointer = 0
  g.vertexNum = vertexNum
  g.edgeMaxSize = 1
  for i := i32(0); i < vertexNum; i++ {
    g.start[i] = -1
  }
  return g
}

func addEdge(g *directedGraph, from i32, to i32) {
  if g.pointer == g.edgeMaxSize {
    g.edgeMaxSize *= 2
    g.edge = make([]directedEdge, g.edgeMaxSize)
  }
  g.edge[g.pointer] = directedEdge{to, g.start[from]}
  g.start[from] = g.pointer++
}

const mod i32 = 1000000007

func modPow(r i32, n i32) i32 {
  t := i32(1)
  s := r
  for n > 0 {
    if n & 1 == 1 {
      t = t * s % mod
    }
    s = s * s % mod
    n >>= 1
  }
  return t
}

type node struct {
  one i32
  zero i32
}

func merge(a []node, n i32) node {
  one := i64(0)
  zero := i64(1)
  total := i64(1)
  for i := i32(0); i < n; i++ {
    one = one * a[i].zero + zero * a[i].one % mod
    zero = zero * a[i].zero % mod
    total = total * (a[i].zero + a[i].one) % mod
  }
  return node{one, (total + mod - one) % mod}
}

type dequeVal node

type deque struct {
  array []dequeVal
  front i32
  last i32
  mask i32
}

func newDeque() *deque {
  const len i32 = 2
  d := &deque{}
  d.array = make([]dequeVal, len)
  d.front = d.last = 0
  d.mask = len - 1
  return d
}

func freeDeque(d *deque) {
  free(d.array)
  free(d)
}

func getSize(d *deque) i32 {
  return (d.last + (~d.front + 1)) & d.mask
}

func dequeRealloc(d *deque) {
  array := make([]dequeVal, 2 * (d.mask + 1))
  k := i32(0)
  for i := d.front; i != d.last; i = (i + 1) & d.mask {
    array[k] = d.array[i]
    k++
  }
  free(d.array)
  d.array = array
  d.front = 0
  d.last = k
  d.mask = 2 * d.mask + 1
}

func getAt(d *deque, x i32) dequeVal {
  return d.array[(d.front + x) & d.mask]
}

func assignAt(d *deque, x i32, v dequeVal) {
  d.array[(d.front + x) & d.mask] = v
}

func pushFront(d *deque, v dequeVal) {
  if (d.last + 1) & d.mask == d.front {
    dequeRealloc(d)
  }
  d.front = (d.front + d.mask) & d.mask
  d.array[d.front] = v
}

func cmpDequeSize(a, b unsafe.Pointer) int {
  p := *(*deque)(a)
  q := *(*deque)(b)
  d := getSize(p) - getSize(q)
  if d == 0 {
    return 0
  }
  if d > 0 {
    return -1
  }
  return 1
}

func run() {
  var n i32
  fmt.Scanf("%d", &n)
  p := make([]i32, n + 1)
  depth := make([]i32, n + 1)
  cnt := make([]i32, n + 1)
  cnt[0] = 1
  g := newGraph(n + 1)
  for i := i32(1); i <= n; i++ {
    fmt.Scanf("%d", p + i)
    addEdge(g, p[i], i)
    depth[i] = depth[p[i]] + 1
    cnt[depth[i]]++
  }
  dp := make([]*deque, n + 1)
  child := make([]*deque, n + 1)
  lst := make([]node, n + 1)
  for i := n; i >= 0; i-- {
    v := i
    if g.start[v] == -1 {
      dp[v] = newDeque()
      pushFront(dp[v], node{1, 1})
      continue
    }
    len := i32(0)
    for p := g.start[v]; p != -1; p = g.edge[p].next {
      u := g.edge[p].vertex
      child[len] = dp[u]
      len++
    }
    if len > 1 {
      sort.Slice(child, cmpDequeSize)
      for d := i32(0); d < getSize(child[1]); d++ {
        j := i32(0)
        for j < len && d < getSize(child[j]); j++ {
          lst[j] = getAt(child[j], d)
        }
        assignAt(child[0], d, merge(lst, j))
      }
      for j := i32(1); j < len; j++ {
        freeDeque(child[j])
      }
    }
    dp[v] = child[0]
    pushFront(dp[v], node{1, 1})
  }
  ans := i64(0)
  for i := i32(0); i < getSize(dp[0]); i++ {
    ans += (i64(mod_pow(2, n + 1 - cnt[i])) * dp[0].array[(dp[0].front + i) & dp[0].mask].one) % mod
  }
  fmt.Printf("%d\n", ans % mod)
}

func main() {
  run()
}

