#######
# Class definition for BIT (Binary Indexed Tree)
# Initialize an instance of BIT with a given size N
#######
type BIT struct {
	size int
	tree []int
	depth int
}

func NewBIT(N int) *BIT {
	bit := &BIT{size: N, tree: make([]int, N+1), depth: N.BitLen()}
	return bit
}

// Helper function to calculate the sum of bits from index i to 0
func (bit *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += bit.tree[i]
		i &= i - 1 // Bitwise AND with the rightmost set bit
	}
	return ret
}

// Function to calculate the sum of bits from left index l to right index r
func (bit *BIT) Bitsum(l, r int) int {
	if r < 0 {
		return bit._bitsum(l)
	}
	return bit._bitsum(r) - bit._bitsum(l)
}

// Function to add a value x to the index i in the tree
func (bit *BIT) Bitadd(i, x int) {
	i++ // Index i is 1-based in the tree
	for i <= bit.size {
		bit.tree[i] += x
		i += i & -i // Bitwise right propagation
	}
}

// Read input values
var n int
fmt.Scan(&n)

// Calculate the size of the BIT tree
m := n * (n + 1) / 4

// Read input array a
a := make([]int, n)
for i := range a {
	fmt.Scan(&a[i])
}

// Create a dictionary d to map each unique value in a to its index
d := make(map[int]int)
_a := make([]int, 0, n)
for _, x := range a {
	if _, ok := d[x]; !ok {
		d[x] = len(d)
		_a = append(_a, x)
	}
}

// Replace the original array a with its indices in the dictionary d
for i, x := range a {
	a[i] = d[x]
}

// Function to check if a given value X is a valid answer
func check(X int) bool {
	b := make([]int, n+1)
	for i, x := range a {
		b[i+1] = (x >= X) * 2 - 1
	}
	for i := 1; i <= n; i++ {
		b[i] += b[i-1]
	}
	c := min(b)
	b = make([]int, n+1)
	for i, x := range b {
		b[i] = x - c
	}
	bit := NewBIT(max(b) + 2) // Initialize BIT tree with the maximum value in b + 2
	ans := 0
	for _, x := range b {
		ans += bit.Bitsum(x + 1) // Calculate the sum of bits from index x+1 to the end
		bit.Bitadd(x, 1)         // Add 1 to the index x in the tree
	}
	return ans >= m
}

// Binary search to find the answer
t := []int{len(_a), 0}
for t[0]-t[1] > 1 {
	mid := (t[0] + t[1]) / 2
	if check(mid) {
		t[0] = mid
	} else {
		t[1] = mid
	}
}

// Print the answer
fmt.Println(_a[t[1]])

