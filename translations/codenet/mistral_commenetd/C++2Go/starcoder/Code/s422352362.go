
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Define the size of the array
const MAX_N = 200005

// Initialize arrays
var a [MAX_N]int64
var pre [MAX_N]int64
var last [MAX_N]int64

func main() {
	// Read the number of elements in the array
	var n int
	fmt.Scanf("%d\n", &n)

	// Read the elements of the array
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d\n", &a[i])
		// Initialize pre and last arrays
		pre[i] = pre[i-1] + a[i]
		last[i] = last[i+1] + a[i]
	}

	// Initialize sum of prefix and suffix arrays to zero
	var sumpre, sumlast int64

	// Calculate prefix sum
	for i := 1; i < n; i++ {
		sumpre += a[i]
		pre[i] = sumpre
	}

	// Calculate suffix sum
	for i := n; i > 0; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}

	// Initialize difference as maximum long long value
	var d int64 = math.MaxInt64

	// Find the minimum difference between prefix and suffix sums
	for i := 1; i < n; i++ {
		d = min(d, abs(pre[i] - last[i+1]))
	}

	// Print the minimum difference
	fmt.Printf("%d\n", d)
}

