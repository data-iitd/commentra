package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// BIT is a data structure that supports efficient queries and updates on a binary array
type BIT struct {
	size  int
	tree  []int
	depth int
}

// NewBIT returns a new BIT with the given size
func NewBIT(size int) *BIT {
	return &BIT{
		size:  size,
		tree:  make([]int, size+1),
		depth: size.bitLen(),
	}
}

// bitLen returns the number of bits required to represent an integer
func bitLen(n int) int {
	if n == 0 {
		return 0
	}
	return 1 + bitLen(n>>1)
}

// bitsum returns the sum of the elements in the range [l, r]
func (b *BIT) bitsum(l, r int) int {
	ret := 0
	for l <= r {
		ret += b.tree[l]
		l += l & -l
	}
	return ret
}

// bitadd adds the value x to the element at index i
func (b *BIT) bitadd(i, x int) {
	i++
	for i <= b.size {
		b.tree[i] += x
		i += i & -i
	}
}

// check returns whether the given value X can be achieved
func check(a []int, X int) bool {
	b := make([]int, len(a)+1)
	b[0] = 1
	for i := 0; i < len(a); i++ {
		b[i+1] = b[i] + (a[i] >= X)
	}
	c := min(b)
	b = [x - c for x in b]
	bit := NewBIT(max(b) + 2)
	ans := 0
	for x := range b {
		ans += bit.bitsum(x+1)
		bit.bitadd(x, 1)
	}
	return ans >= X
}

// min returns the minimum value in the given list
func min(a []int) int {
	m := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < m {
			m = a[i]
		}
	}
	return m
}

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine())
	// Calculate the target value m based on the number of elements
	m := n * (n + 1) / 4
	// Read the input array and convert it to a list of integers
	a := make([]int, n)
	for i := range a {
		a[i], _ = strconv.Atoi(readLine())
	}
	// Create a sorted list of unique values from a, including 0
	_a := make([]int, 0, len(a)+1)
	_a = append(_a, 0)
	for _, x := range a {
		if!contains(_a, x) {
			_a = append(_a, x)
		}
	}
	// Map original values to their indices in the sorted list
	d := make(map[int]int)
	for i, x := range _a {
		d[x] = i
	}
	// Replace original values in a with their corresponding indices
	a = [len(a)]int{}
	for i, x := range a {
		a[i] = d[x]
	}

	// Initialize the binary search bounds
	t := [2]int{len(_a), 0}
	// Perform binary search to find the maximum value that satisfies the condition
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(a, mid) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}

	// Print the result corresponding to the found index
	fmt.Println(_a[t[1]])
}

// readLine reads a string line from stdin
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, err := buf.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

// contains returns whether the given list contains the given value
func contains(a []int, x int) bool {
	for _, y := range a {
		if y == x {
			return true
		}
	}
	return false
}

