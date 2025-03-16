/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
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
	n, q int
	C    []int
	Q    []Query

	P       [500000 + 50]int
	Answers [500000 + 50]int
)

type Query struct {
	idx, l, r int
}

func main() {
	// Read input
	n, q = ReadInt2()
	C = ReadIntSlice(n)

	// Initialize P array and Fenwick Tree
	for i := 1; i <= n; i++ {
		P[i] = -1
	}

	// Process queries
	for i := 0; i < q; i++ {
		l, r := ReadInt2()
		query := Query{idx: i, l: l, r: r}
		Q = append(Q, query)
	}

	sort.SliceStable(Q, func(i, j int) bool { return Q[i].r < Q[j].r })
	ft := NewFenwickTree(500000 + 50)

	k := 0
	for _, query := range Q {
		// Process each query
		for k < query.r {
			if P[C[k]] != -1 {
				ft.Add(P[C[k]]+1, -1)
			}
			P[C[k]] = k
			ft.Add(k+1, 1)

			k++
		}

		// Calculate answer and print it
		Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l-1)
	}

	// Print answers
	for i := 0; i < q; i++ {
		// fmt.Println(Answers[i])
		PrintfBufStdout("%d\n", Answers[i])
	}
	stdout.Flush()
}

// Public methods
// ft := NewFenwickTree(200000 + 5)
// s := ft.Sum(i) 						// Sum of [1, i](1-based)
// ft.Add(i, x) 							// Add x to i(1-based)
// idx := ft.LowerBound(w) 		// minimum idx such that bit.Sum(idx) >= w

type FenwickTree struct {
	dat     []int
	n       int
	minPow2 int
}

// n(>=1) is number of elements of original data
func NewFenwickTree(n int) *FenwickTree {
	ft := new(FenwickTree)

	ft.dat = make([]int, n+1)
	ft.n = n

	ft.minPow2 = 1
	for {
		if (ft.minPow2 << 1) > n {
			break
		}
		ft.minPow2 <<= 1
	}

	return ft
}

// Sum of [1, i](1-based)
func (ft *FenwickTree) Sum(i int) int {
	s := 0

	for i > 0 {
		s += ft.dat[i]
		i -= i & (-i)
	}

	return s
}

// Add x to i(1-based)
func (ft *FenwickTree) Add(i, x int) {
	for i <= ft.n {
		ft.dat[i] += x
		i += i & (-i)
	}
}

// LowerBound returns minimum i such that bit.Sum(i) >= w.
func (ft *FenwickTree) LowerBound(w int) int {
	if w <= 0 {
		return 0
	}

	x := 0
	for k := ft.minPow2; k > 0; k /= 2 {
		if x+k <= ft.n && ft.dat[x+k] < w {
			w -= ft.dat[x+k]
			x += k
		}
	}

	return x + 1
}
