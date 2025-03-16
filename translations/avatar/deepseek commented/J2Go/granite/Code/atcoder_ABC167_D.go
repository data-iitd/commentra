

package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007
const MAX = int(1e6) + 1
const LMAX = int64(1e18) + 1

func main() {
	// Read the number of elements N and the value K
	reader := bufio.NewReader(os.Stdin)
	N, _ := fmt.Fscanf(reader, "%d\n", &N)
	K, _ := fmt.Fscanf(reader, "%d\n", &K)

	// Read the array A with N elements, adjusting each element by -1 for 0-based indexing
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d\n", &A[i])
		A[i]--
	}

	// Set to track visited indices
	used := make(map[int]bool)

	// Arrays to store index and position information
	idx := make([]int, N)
	pos := make([]int, N)

	// Initialize variables for cycle detection
	next, cur := 0, 0

	// Detect the cycle in the array A
	for!used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	// Calculate the length of the cycle and adjust the position based on K
	a := int64(cur - idx[next])
	b := int64(idx[next])
	ans := int((10000*a+K-b)%a + b)

	// Adjust the answer if necessary based on the cycle length
	if b > K {
		ans = int(K)
	}

	// Output the final position
	fmt.Println(pos[ans] + 1)
}

