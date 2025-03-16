/*
URL:
https://atcoder.jp/contests/dp/tasks/dp_v
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadRuneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

const (
	// General purpose
	MOD = 1000000000 + 7
	// MOD          = 998244353
	ALPHABET_NUM = 26
	INF_INT64    = math.MaxInt64
	INF_BIT60    = 1 << 60
	INF_INT32    = math.MaxInt32
	INF_BIT30    = 1 << 30
	NIL          = -1

	// for dijkstra, prim, and so on
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

func init() {
	// bufio.ScanWords <---> bufio.ScanLines
	ReadString = newReadString(os.Stdin, bufio.ScanWords)
	stdout = bufio.NewWriter(os.Stdout)
}

var (
	n, m  int
	edges [][]int
)

func main() {
	// Read input: number of nodes and edges
	n, m = ReadInt2()
	for i := 0; i < n-1; i++ {
		x, y := ReadInt2()
		x--
		y--

		e := []int{x, y}
		edges = append(edges, e)
	}

	// Initialize the disjoint set data structure
	f := func(x, y T) T { return T(int(x) * int(y) % m) }
	g := func(v T, p int) T { return v + 1 }
	s := NewReRootingSolver(n, edges, 1, f, g)

	// Query the product of subtrees for all nodes and print the result
	for i := 0; i < n; i++ {
		fmt.Println(s.Query(i) - 1)
	}
}

type T int

type ReRootingSolver struct {
	NodeCount int

	Adjacents         [][]int
	IndexForAdjacents [][]int

	Res []T
	DP  [][]T

	Identity    T
	Operate     func(l, r T) T
	OperateNode func(v T, p int) T
}

func NewReRootingSolver(
	nodeCount int, edges [][]int, identity T, operate func(l, r T) T, operateNode func(v T, p int) T,
) *ReRootingSolver {
	s := new(ReRootingSolver)

	s.NodeCount = nodeCount
	s.Identity = identity
	s.Operate = operate
	s.OperateNode = operateNode

	s.Adjacents = make([][]int, nodeCount)
	s.IndexForAdjacents = make([][]int, nodeCount)
	for _, e := range edges {
		s.IndexForAdjacents[e[0]] = append(s.IndexForAdjacents[e[0]], len(s.Adjacents[e[1]]))
		s.IndexForAdjacents[e[1]] = append(s.IndexForAdjacents[e[1]], len(s.Adjacents[e[0]]))
		s.Adjacents[e[0]] = append(s.Adjacents[e[0]], e[1])
		s.Adjacents[e[1]] = append(s.Adjacents[e[1]], e[0])
	}

	s.DP = make([][]T, len(s.Adjacents))
	s.Res = make([]T, len(s.Adjacents))

	for i := 0; i < len(s.Adjacents); i++ {
		s.DP[i] = make([]T, len(s.Adjacents[i]))
	}

	if s.NodeCount > 1 {
		s.Initialize()
	} else {
		s.Res[0] = s.OperateNode(s.Identity, 0)
	}

	return s
}

func (s *ReRootingSolver) Query(node int) T {
	return s.Res[node]
}

func (s *ReRootingSolver) Initialize() {
	parents, order := make([]int, s.NodeCount), make([]int, s.NodeCount)

	// InitOrderedTree
	index := 0
	stack := []int{}
	stack = append(stack, 0)
	parents[0] = -1
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		order[index] = node
		index++
		for i := 0; i < len(s.Adjacents[node]); i++ {
			adjacent := s.Adjacents[node][i]
			if adjacent == parents[node] {
				continue
			}
			stack = append(stack, adjacent)
			parents[adjacent] = node
		}
	}

	// fromLeaf
	for i := len(order) - 1; i >= 1; i-- {
		node := order[i]
		parent := parents[node]

		accum := s.Identity
		parentIndex := -1
		for j := 0; j < len(s.Adjacents[node]); j++ {
			if s.Adjacents[node][j] == parent {
				parentIndex = j
				continue
			}
			accum = s.Operate(accum, s.DP[node][j])
		}
		s.DP[parent][s.IndexForAdjacents[node][parentIndex]] = s.OperateNode(accum, node)
		accum = s.Operate(accum, s.DP[node][j])
		s.DP[node][j] = accum
	}

	// toLeaf
	for i := 0; i < len(order); i++ {
		node := order[i]
		accum := s.Identity
		accumsFromTail := make([]T, len(s.Adjacents[node]))
		accumsFromTail[len(accumsFromTail)-1] = s.Identity
		for j := len(accumsFromTail) - 1; j >= 1; j-- {
			accumsFromTail[j-1] = s.Operate(s.DP[node][j], accumsFromTail[j])
		}
		for j := 0; j < len(accumsFromTail); j++ {
			s.DP[s.Adjacents[node][j]][s.IndexForAdjacents[node][j]] = s.OperateNode(s.Operate(accum, accumsFromTail[j]), node)
			accum = s.Operate(accum, s.DP[node][j])
		}
		s.Res[node] = s.OperateNode(accum, node)
	}
}