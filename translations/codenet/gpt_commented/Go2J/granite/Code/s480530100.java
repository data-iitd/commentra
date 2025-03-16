
import java.util.Scanner;

public class s480530100{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        BIT bit = new BIT(n);
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            bit.add(i, a);
        }
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt();
            if (t == 0) {
                int p = scanner.nextInt();
                int x = scanner.nextInt();
                bit.add(p, x);
            } else {
                int l = scanner.nextInt();
                int r = scanner.nextInt();
                System.out.println(bit.sum(l, r));
            }
        }
    }
}

class BIT {
    private int[] data;
    private int n;

    public BIT(int n) {
        this.n = n;
        data = new int[n];
    }

    public void add(int p, int x) {
        for (int i = p; i < n; i |= i + 1) {
            data[i] += x;
        }
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    private int sum(int r) {
        int ret = 0;
        for (int i = r - 1; i >= 0; i = (i & (i + 1)) - 1) {
            ret += data[i];
        }
        return ret;
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.data[r-1] // Add the value at index r-1
		r -= r & -r      // Move to the parent index
	}
	return s // Return the calculated sum
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
type BIT struct {
	n    int     // Number of elements in the tree
	data []int   // Array to store the tree data
}

// FenwickTree initializes a new Binary Indexed Tree with n elements.
func FenwickTree(n int) *BIT {
	var ret BIT
	ret.n = n
	ret.data = make([]int, n) // Create a slice to hold the tree data
	return &ret
}

// Add updates the Fenwick Tree by adding x to the element at position p.
func (b *BIT) Add(p, x int) {
	p++ // Increment p to match the 1-based index used in Fenwick Tree
	for p <= b.n {
		b.data[p-1] += x // Update the tree data
		p += p & -p      // Move to the next index
	}
}

// Sum calculates the sum of elements in the range [l, r).
func (b *BIT) Sum(l, r int) int {
	return b.sum(r) - b.sum(l) // Return the difference of sums
}

// sum calculates the prefix sum from the start to index r.
func (b *BIT) sum(r int) int {
	s := 0 // Initialize sum
	for r > 0 {
		s += b.