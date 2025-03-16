
package main

import (
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  var n, m int
  var graph [][]int
  var visited []bool
  var color []int
  var one, bipartite, count int64
  var mujun bool

  fmt.Scan(&n, &m)
  graph = make([][]int, n)
  for i := 0; i < n; i++ {
    graph[i] = make([]int, 0)
  }
  for i := 0; i < m; i++ {
    var u, v int
    fmt.Scan(&u, &v)
    u--
    v--
    graph[u] = append(graph[u], v)
    graph[v] = append(graph[v], u)
  }
  visited = make([]bool, n)
  color = make([]int, n)
  for i := 0; i < n; i++ {
    color[i] = -1
  }
  for i := 0; i < n; i++ {
    if visited[i] {
      continue
    }
    count++
    mujun = false
    var kind int
    kind = dfs(i, 0)
    if kind == 1 {
      one++
    } else if !mujun {
      bipartite++
    }
  }
  var total int64
  total = one * (2*n - one)
  total += (count - one) * (count - one)
  total += bipartite * bipartite
  fmt.Println(total)
}

func dfs(a, c int) int {
  if visited[a] {
    if color[a] >= 0 && color[a] != c {
      mujun = true
    }
    return 0
  }
  visited[a] = true
  color[a] = c
  var total int
  total = 1
  for _, b := range graph[a] {
    total += dfs(b, 1-c)
  }
  return total
}

