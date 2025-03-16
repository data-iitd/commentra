
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type directedEdge struct {
	vertex int32
	next   int32
}

type directedGraph struct {
	edge        []*directedEdge
	start       []int32
	pointer     int32
	vertex_num int32
	edge_max_size int32
}

func newGraph(vertex_num int32) *directedGraph {
	g := &directedGraph{}
	g.edge = make([]*directedEdge, 1)
	g.start = make([]int32, vertex_num)
	g.pointer = 0
	g.vertex_num = vertex_num
	g.edge_max_size = 1
	for i := int32(0); i < vertex_num; i++ {
		g.start[i] = -1
	}
	return g
}

func addEdge(g *directedGraph, from int32, to int32) {
	if g.pointer == g.edge_max_size {
		g.edge_max_size *= 2
		g.edge = append(g.edge, make([]*directedEdge, g.edge_max_size-g.pointer)...)
	}
	g.edge[g.pointer] = &directedEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

const mod = 1000000007

func modPow(r int32, n int32) int32 {
	t := int64(1)
	s := int64(r)
	for n > 0 {
		if n&1 == 1 {
			t = (t * s) % mod
		}
		s = (s * s) % mod
		n >>= 1
	}
	return int32(t)
}

type dequeVal struct {
	one int32
	zero int32
}

type Deque struct {
	array []*dequeVal
	front int
	last int
	mask int
}

func newDeque() *Deque {
	d := &Deque{}
	d.array = make([]*dequeVal, 2)
	d.front = 0
	d.last = 0
	d.mask = 1
	return d
}

func (d *Deque) getSize() int {
	return (d.last + d.mask - d.front) & d.mask
}

func (d *Deque) realloc() {
	newArray := make([]*dequeVal, 2*d.mask+1)
	k := 0
	for i := d.front; i!= d.last; i = (i + 1) & d.mask {
		newArray[k] = d.array[i]
		k++
	}
	d.array = newArray
	d.front = 0
	d.last = k
	d.mask = 2 * d.mask + 1
}

func (d *Deque) getAt(x int) *dequeVal {
	return d.array[(d.front + x) & d.mask]
}

func (d *Deque) assignAt(x int, v *dequeVal) {
	d.array[(d.front + x) & d.mask] = v
}

func (d *Deque) pushFront(v *dequeVal) {
	if d.getSize()+1 == d.mask+1 {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b interface{}) int {
	pa := a.(*Deque)
	pb := b.(*Deque)
	da := pa.getSize()
	db := pb.getSize()
	if da-db == 0 {
		return 0
	} else if da-db > 0 {
		return -1
	} else {
		return 1
	}
}

func run() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	p := make([]int32, n+1)
	depth := make([]int32, n+1)
	cnt := make([]int32, n+1)
	cnt[0] = 1
	g := newGraph(n + 1)
	for i := 1; i <= n; i++ {
		p[i], _ = strconv.Atoi(reader.ReadLine()[2:])
		addEdge(g, p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*Deque, n+1)
	child := make([]*Deque, n+1)
	lst := make([]*dequeVal, n+1)
	for i := n; i >= 0; i-- {
		v := int32(i)
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(&dequeVal{1, 1})
			continue
		}
		len := 0
		for p := g.start[v]; p!= -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			sort.Slice(child[:len], cmpDequeSize)
			for d := 0; d < child[1].getSize(); d++ {
				j := 0
				for ; j < len && d < child[j].getSize(); j++ {
					lst[j] = child[j].getAt(d)
				}
				dp[v].pushFront(merge(lst[:j], j))
			}
			for j := 1; j < len; j++ {
				dp[v].last = dp[v].front
				dp[v].mask = dp[v].last - 1
				for i := dp[v].front; i!= dp[v].last; i = (i + 1) & dp[v].mask {
					dp[v].array[i] = nil
				}
				dp[v].array = dp[v].array[:dp[v].last]
				child[j] = nil
			}
		}
		dp[v].pushFront(&dequeVal{1, 1})
	}
	ans := int64(0)
	for i := 0; i < dp[0].getSize(); i++ {
		ans = (ans + int64(modPow(2, n+1-cnt[i]))*dp[0].getAt(i).one) % mod
	}
	fmt.Println(ans)
}

func main() {
	run()
}

This is the translated Go code for the given C code. It includes the necessary data structures and functions to perform the same operations as the original C code. The main function calls the `run` function to execute the program.