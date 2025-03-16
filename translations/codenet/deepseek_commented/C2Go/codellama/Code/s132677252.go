#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

type i32 int32
type i64 int64

// Define a structure for a directed edge in the graph
type directed_edge struct {
  vertex int32 // The destination vertex of the edge
  next int32   // The index of the next edge in the adjacency list
}

// Define a structure for the directed graph
type directedGraph struct {
  edge []directed_edge // Array of edges
  start []int32         // Array of start pointers for each vertex
  pointer int32        // Current number of edges
  vertex_num int32     // Number of vertices
  edge_max_size int32  // Maximum size of the edge array
}

// Function to initialize a new graph with a given number of vertices
func new_graph(vertex_num int32) *directedGraph {
  g := &directedGraph{}
  g.edge = make([]directed_edge, 1)
  g.start = make([]int32, vertex_num)
  g.pointer = 0
  g.vertex_num = vertex_num
  g.edge_max_size = 1
  for i := int32(0); i < vertex_num; i++ {
    g.start[i] = -1 // Initialize all start pointers to -1 (no edges initially)
  }
  return g
}

// Function to add a directed edge to the graph
func add_edge(g *directedGraph, from int32, to int32) {
  if g.pointer == g.edge_max_size {
    g.edge_max_size *= 2
    g.edge = make([]directed_edge, g.edge_max_size)
  }
  g.edge[g.pointer] = directed_edge{to, g.start[from]} // Set the new edge and update the start pointer
  g.start[from] = g.pointer++ // Update the start pointer to the new edge
}

// Define the modulo constant
const mod int32 = 1000000007

// Function to compute r^n % mod using exponentiation by squaring
func mod_pow(r int32, n int32) int32 {
  t := int32(1)
  s := r
  for n > 0 {
    if n & 1 == 1 {
      t = (int64(t) * s) % mod
    }
    s = (int64(s) * s) % mod
    n >>= 1
  }
  return t
}

// Define a structure for a node in the dynamic programming array
type node struct {
  one int32  // Number of ways to have exactly one edge
  zero int32 // Number of ways to have exactly zero edges
}

// Function to merge two nodes in the dynamic programming array
func merge(a []node, n int32) node {
  one := int64(0)
  zero := int64(1)
  total := int64(1)
  for i := int32(0); i < n; i++ {
    one = (one * a[i].zero + zero * a[i].one) % mod
    zero = zero * a[i].zero % mod
    total = total * (a[i].zero + a[i].one) % mod
  }
  return node{one, (total + mod - one) % mod}
}

// Define the type for values stored in the deque
type deque_val node

// Define a structure for the deque
type Deque struct {
  array []deque_val
  front int
  last int
  mask int
}

// Function to initialize a new deque
func new_deque() *Deque {
  const len int = 2
  d := &Deque{}
  d.array = make([]deque_val, len)
  d.front = d.last = 0
  d.mask = len - 1
  return d
}

// Function to free the memory allocated for a deque
func free_deque(d *Deque) {
  free(d.array)
  free(d)
}

// Function to get the number of elements in the deque
func get_size(d *Deque) int {
  return (d.last + (~d.front + 1)) & d.mask
}

// Function to reallocate the deque when necessary
func deque_realloc(d *Deque) {
  array := make([]deque_val, 2 * (d.mask + 1))
  k := 0
  for i := d.front; i != d.last; i = (i + 1) & d.mask {
    array[k++] = d.array[i]
  }
  free(d.array)
  d.array = array
  d.front = 0
  d.last = k
  d.mask = 2 * d.mask + 1
}

// Function to get the value at a specific index in the deque
func get_at(d *Deque, x int) deque_val {
  return d.array[(d.front + x) & d.mask]
}

// Function to assign a value at a specific index in the deque
func assign_at(d *Deque, x int, v deque_val) {
  d.array[(d.front + x) & d.mask] = v
}

// Function to add an element to the front of the deque
func push_front(d *Deque, v deque_val) {
  if(((d.last + 1) & d.mask) == d.front) {
    deque_realloc(d)
  }
  d.front = (d.front + d.mask) & d.mask
  d.array[d.front] = v
}

// Function to compare the sizes of two deques
func cmp_deque_size(a, b unsafe.Pointer) int {
  p := *(*Deque)(a)
  q := *(*Deque)(b)
  d := get_size(p) - get_size(q)
  return d == 0 ? 0 : d > 0 ? -1 : 1
}

// Function to run the main logic of the program
func run() {
  var n int32
  fmt.Scanf("%d", &n) // Read the number of vertices
  p := make([]int32, n + 1) // Array to store parent pointers
  depth := make([]int32, n + 1) // Array to store depths of vertices
  cnt := make([]int32, n + 1) // Array to count vertices at each depth
  cnt[0] = 1 // There is one way to have zero edges (the root itself)
  g := new_graph(n + 1) // Initialize the graph
  for i := int32(1); i <= n; i++ {
    fmt.Scanf("%d", p + i) // Read the parent of each vertex
    add_edge(g, p[i], i) // Add the edge to the graph
    depth[i] = depth[p[i]] + 1 // Calculate the depth of each vertex
    cnt[depth[i]]++ // Increment the count of vertices at the current depth
  }
  dp := make([]*Deque, n + 1) // Array to store dynamic programming results
  child := make([]*Deque, n + 1) // Array to store child deques
  lst := make([]node, n + 1) // Array to store merged nodes
  for i := n; i >= 0; i-- {
    v := i
    if g.start[v] == -1 {
      dp[v] = new_deque()
      push_front(dp[v], node{1, 1}) // Initialize the dp array for leaf nodes
      continue
    }
    len := 0
    for p := g.start[v]; p != -1; p = g.edge[p].next {
      u := g.edge[p].vertex
      child[len++] = dp[u] // Collect child deques
    }
    if len > 1 {
      qsort(unsafe.Pointer(&child[1]), len, unsafe.Sizeof(child[0]), cmp_deque_size) // Sort child deques by size
      for d := 0; d < get_size(child[1]); d++ {
        j := 0
        for j < len && d < get_size(child[j]); j++ {
          lst[j] = get_at(child[j], d) // Get nodes at the current depth
        }
        assign_at(child[0], d, merge(lst, j)) // Merge nodes and assign to the first child deque
      }
      for j := 1; j < len; j++ {
        free_deque(child[j]) // Free memory of unused child deques
      }
    }
    dp[v] = child[0] // Assign the merged deque to the current vertex
    push_front(dp[v], node{1, 1}) // Add the current node to the dp array
  }
  ans := int64(0)
  for i := 0; i < get_size(dp[0]); i++ {
    ans += (int64(mod_pow(2, n + 1 - cnt[i])) * dp[0].array[(dp[0].front + i) & dp[0].mask].one) % mod // Calculate the answer
  }
  fmt.Printf("%d\n", ans % mod) // Print the result
}

// Main function to run the program
func main() {
  run()
}

