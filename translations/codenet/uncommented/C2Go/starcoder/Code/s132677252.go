package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const mod = 1000000007

func mod_pow(r, n int) int {
	t := 1
	s := r
	for n > 0 {
		if n&1 > 0 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return t
}

type node struct {
	one  int
	zero int
}

func merge(a []node, n int) node {
	one := 0
	zero := 1
	total := 1
	for i := 0; i < n; i++ {
		one = (one*a[i].zero + zero*a[i].one) % mod
		zero = zero * a[i].zero % mod
		total = total * (a[i].zero + a[i].one) % mod
	}
	return node{one, (total + mod - one) % mod}
}

type deque_val node

type deque struct {
	array []deque_val
	front int
	last  int
	mask  int
}

func new_deque() *deque {
	d := &deque{}
	d.array = make([]deque_val, 2)
	d.front = 0
	d.last = 0
	d.mask = 1
	return d
}

func free_deque(d *deque) {
	d.array = nil
	d.front = 0
	d.last = 0
	d.mask = 0
}

func get_size(d *deque) int {
	return (d.last + (~d.front + 1)) & d.mask
}

func deque_realloc(d *deque) {
	array := make([]deque_val, 2*(d.mask+1))
	k := 0
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		array[k] = d.array[i]
		k++
	}
	d.array = array
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

func get_at(d *deque, x int) deque_val {
	return d.array[(d.front+x)&d.mask]
}

func assign_at(d *deque, x int, v deque_val) {
	d.array[(d.front+x)&d.mask] = v
}

func push_front(d *deque, v deque_val) {
	if ((d.last+1)&d.mask) == d.front {
		deque_realloc(d)
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmp_deque_size(a, b *deque) int {
	d := get_size(a) - get_size(b)
	if d == 0 {
		return 0
	}
	if d > 0 {
		return -1
	}
	return 1
}

func run() {
	n := 0
	fmt.Fscanf(os.Stdin, "%d\n", &n)
	p := make([]int, n+1)
	depth := make([]int, n+1)
	cnt := make([]int, n+1)
	cnt[0] = 1
	g := new_graph(n + 1)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(os.Stdin, "%d\n", &p[i])
		add_edge(g, p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]node, n+1)
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = new_deque()
			push_front(dp[v], node{1, 1})
			continue
		}
		len := 0
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			sort.Slice(child, func(i, j int) bool {
				return get_size(child[i]) < get_size(child[j])
			})
			for d := 0; d < get_size(child[1]); d++ {
				j := 0
				for ; j < len && d < get_size(child[j]); j++ {
					lst[j] = get_at(child[j], d)
				}
				assign_at(child[0], d, merge(lst[:j], j))
			}
			for j := 1; j < len; j++ {
				free_deque(child[j])
			}
		}
		dp[v] = child[0]
		push_front(dp[v], node{1, 1})
	}
	ans := 0
	for i := 0; i < get_size(dp[0]); i++ {
		ans += (mod_pow(2, n+1-cnt[i]) * get_at(dp[0], i).one) % mod
	}
	fmt.Printf("%d\n", ans%mod)
}

func new_graph(vertex_num int) *graph {
	g := &graph{}
	g.edge = make([]graph_edge, 1)
	g.start = make([]int, vertex_num)
	g.pointer = 0
	g.vertex_num = vertex_num
	g.edge_max_size = 1
	for i := 0; i < vertex_num; i++ {
		g.start[i] = -1
	}
	return g
}

func add_edge(g *graph, from, to int) {
	if g.pointer == g.edge_max_size {
		g.edge_max_size *= 2
		g.edge = append(g.edge, make([]graph_edge, g.edge_max_size)...)
	}
	g.edge[g.pointer] = graph_edge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

func main() {
	run()
}

