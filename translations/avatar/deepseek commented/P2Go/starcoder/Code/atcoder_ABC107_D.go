package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// BIT is a data structure that supports the following operations:
// 1. Add x to the value at the index i
// 2. Calculate the sum of the values from 1 to i
// 3. Calculate the sum of the values from i to j
type BIT struct {
	size int
	tree []int
}

// NewBIT returns a new BIT structure
func NewBIT(n int) *BIT {
	return &BIT{
		size: n,
		tree: make([]int, n+1),
	}
}

// Add adds x to the value at the index i
func (bit *BIT) Add(i, x int) {
	i++
	for ; i <= bit.size; i += i & -i {
		bit.tree[i] += x
	}
}

// Sum returns the sum of the values from 1 to i
func (bit *BIT) Sum(i int) int {
	var ret int
	for ; i > 0; i -= i & -i {
		ret += bit.tree[i]
	}
	return ret
}

// SumRange returns the sum of the values from i to j
func (bit *BIT) SumRange(i, j int) int {
	return bit.Sum(j) - bit.Sum(i-1)
}

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine())
	// Calculate the median position
	m := n * (n + 1) / 4
	// Read the list of elements and convert to indices
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine())
	}
	d := make(map[int]int)
	_a := make([]int, 0, len(a)+1)
	for _, x := range a {
		if _, ok := d[x];!ok {
			_a = append(_a, x)
			d[x] = len(_a) - 1
	}
	a = make([]int, n)
	for i, x := range _a {
		a[i] = d[x]
	}

	// Function to check if the number of inversions is at least m
	func check(X int) bool {
		b := make([]int, n+1)
		for i := 0; i < n; i++ {
			b[i+1] = b[i] + (a[i] >= X)
		}
		for i := 0; i < n; i++ {
			b[i+1] += b[i]
		}
		c := min(b)
		b = make([]int, n+1)
		for i := 0; i < n; i++ {
			b[i+1] = b[i] + (a[i] >= X)
		}
		for i := 0; i < n; i++ {
			b[i+1] -= c
		}
		bit := NewBIT(max(b) + 2)
		ans := 0
		for _, x := range b {
			ans += bit.SumRange(x+1, n+1)
			bit.Add(x, 1)
		}
		return ans >= m
	}

	// Binary search to find the value of X
	t := []int{len(_a), 0}
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid) {
			t[1] = mid
		} else {
			t[0] = mid
	}
	// Output the median value
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

func min(a []int) int {
	ret := a[0]
	for _, x := range a[1:] {
		if x < ret {
			ret = x
	}
	return ret
}

func max(a []int) int {
	ret := a[0]
	for _, x := range a[1:] {
		if x > ret {
			ret = x
	}
	return ret
}

