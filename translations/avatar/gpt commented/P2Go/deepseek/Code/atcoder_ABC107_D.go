package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// BIT struct represents the Binary Indexed Tree
type BIT struct {
	size int
	tree []int
}

// NewBIT initializes a new Binary Indexed Tree
func NewBIT(N int) *BIT {
	return &BIT{
		size: N,
		tree: make([]int, N+1),
	}
}

// bitsum calculates the prefix sum up to index i
func (b *BIT) bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += b.tree[i]
		i ^= i & -i
	}
	return ret
}

// bitadd adds a value x at index i
func (b *BIT) bitadd(i, x int) {
	i++
	for i <= b.size {
		b.tree[i] += x
		i += i & -i
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements
	var n int
	fmt.Fscan(reader, &n)

	// Calculate the target value m based on the number of elements
	m := n * (n + 1) / 4

	// Read the input array and convert it to a list of integers
	var a []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(reader, &x)
		a = append(a, x)
	}

	// Create a sorted list of unique values from a, including 0
	uniqueA := append([]int{0}, a...)
	uniqueA = append(uniqueA, 0)
	sort.Ints(uniqueA)
	uniqueA = uniqueA[:len(uniqueA)-1] // Remove the last duplicate 0

	// Map original values to their indices in the sorted list
	dict := make(map[int]int)
	for i, x := range uniqueA {
		dict[x] = i
	}

	// Replace original values in a with their corresponding indices
	for i := range a {
		a[i] = dict[a[i]]
	}

	// Function to check if a certain value X can be achieved
	check := func(X int) bool {
		// Create a new list b where each element indicates if the corresponding a[i] is >= X
		b := make([]int, n+1)
		for i := 0; i < n; i++ {
			b[i+1] = (a[i] >= X) * 2 - 1
		}
		// Calculate the prefix sums of b
		for i := 1; i <= n; i++ {
			b[i] += b[i-1]
		}
		// Find the minimum value in b
		minB := b[0]
		for i := range b {
			b[i] -= minB
		}
		// Initialize a BIT for the range of b
		bit := NewBIT(max(b) + 2)
		ans := 0
		// Count the number of valid pairs using the BIT
		for _, x := range b {
			ans += bit.bitsum(x + 1)
			bit.bitadd(x, 1)
		}
		return ans >= m
	}

	// Initialize the binary search bounds
	t := []int{len(uniqueA), 0}

	// Perform binary search to find the maximum value that satisfies the condition
	for t[0]-t[1] > 1 {
		mid := (t[0] + t[1]) / 2
		if check(uniqueA[mid]) {
			t[0] = mid
		} else {
			t[1] = mid
		}
	}

	// Print the result corresponding to the found index
	fmt.Fprintln(writer, uniqueA[t[1]])
}

