
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// BIT is a data structure that supports two operations:
// 1. Add a value x to the index i in the tree
// 2. Calculate the sum of bits from index i to 0
type BIT struct {
	size  int
	depth int
	tree  []int
}

// NewBIT returns a new instance of BIT with a given size N
func NewBIT(N int) *BIT {
	tree := make([]int, N+1)
	return &BIT{N, N.bitLen(), tree}
}

// _bitsum returns the sum of bits from index i to 0
func (b *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += b.tree[i]
		i &= i - 1
	}
	return ret
}

// bitsum returns the sum of bits from index l to index r
func (b *BIT) bitsum(l, r int) int {
	return b._bitsum(r) - b._bitsum(l)
}

// bitadd adds a value x to the index i in the tree
func (b *BIT) bitadd(i, x int) {
	i++
	for i <= b.size {
		b.tree[i] += x
		i += i & -i
	}
}

// check returns true if a given value X is a valid answer
func check(a []int, X int) bool {
	b := make([]int, len(a)+1)
	b[0] = 0
	for i := 0; i < len(a); i++ {
		b[i+1] = b[i] + (a[i] >= X)*2 - 1
	}
	for i := 0; i < len(a); i++ {
		b[i+1] += b[i]
	}
	c := min(b)
	b = [len(b)]int{}
	for i := 0; i < len(b); i++ {
		b[i] = b[i] - c
	}
	bit := NewBIT(max(b)+2)
	ans := 0
	for _, x := range b {
		ans += bit.bitsum(x+1)
		bit.bitadd(x, 1)
	}
	return ans >= len(a)*(len(a)+1)/4
}

// min returns the minimum value in a
func min(a []int) int {
	m := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < m {
			m = a[i]
		}
	}
	return m
}

// max returns the maximum value in a
func max(a []int) int {
	m := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > m {
			m = a[i]
		}
	}
	return m
}

func main() {
	// Read input values
	n, _ := strconv.Atoi(readLine())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine())
	}

	// Create a dictionary d to map each unique value in a to its index
	d := make(map[int]int)
	_a := make([]int, 0, len(a)+1)
	for _, x := range a {
		if _, ok := d[x];!ok {
			d[x] = len(_a)
			_a = append(_a, x)
		}
	}

	// Replace the original array a with its indices in the dictionary d
	for i := 0; i < n; i++ {
		a[i] = d[a[i]]
	}

	// Binary search to find the answer
	t := [2]int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(a, mid) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}

	// Print the answer
	fmt.Println(_a[t[1]])
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, err := buf.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

