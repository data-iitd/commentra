package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Class definition for BIT (Binary Indexed Tree)
type BIT struct {
	size int
	tree []int
	depth int
}

// Initialize an instance of BIT with a given size N
func NewBIT(N int) *BIT {
	return &BIT{
		size: N,
		tree: make([]int, N + 1),
		depth: N.bit_length(),
	}
}

// Helper function to calculate the sum of bits from index i to 0
func (bit *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += bit.tree[i]
		i &= i - 1
	}
	return ret
}

// Function to calculate the sum of bits from left index l to right index r
func (bit *BIT) bitsum(l, r int) int {
	if r == -1 {
		return bit._bitsum(l)
	}
	return bit._bitsum(r) - bit._bitsum(l)
}

// Function to add a value x to the index i in the tree
func (bit *BIT) bitadd(i, x int) {
	i += 1
	for i <= bit.size {
		bit.tree[i] += x
		i += i & -i
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	// Calculate the size of the BIT tree
	m := n * (n + 1) / 4

	// Read input array a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Create a dictionary d to map each unique value in a to its index
	d := make(map[int]int)
	_a := append([]int(nil), a...)
	sort.Ints(_a)
	for i, x := range _a {
		d[x] = i
	}

	// Replace the original array a with its indices in the dictionary d
	for i := 0; i < n; i++ {
		a[i] = d[a[i]]
	}

	// Function to check if a given value X is a valid answer
	check := func(X int) bool {
		b := make([]int, n + 1)
		for i := 0; i < n; i++ {
			if a[i] >= X {
				b[i+1] = 1
			} else {
				b[i+1] = -1
			}
		}
		for i := 1; i <= n; i++ {
			b[i] += b[i-1]
		}
		c := min(b)
		for i := 0; i <= n; i++ {
			b[i] -= c
		}
		bit := NewBIT(max(b) + 2)
		ans := 0
		for _, x := range b {
			ans += bit.bitsum(x+1, -1)
			bit.bitadd(x, 1)
		}
		return ans >= m
	}

	// Binary search to find the answer
	t := []int{len(_a), 0}
	for t[0] - t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(mid) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}

	// Print the answer
	fmt.Fprintln(writer, _a[t[1]])
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func bit_length(n int) int {
	length := 0
	for n > 0 {
		n >>= 1
		length++
	}
	return length
}
