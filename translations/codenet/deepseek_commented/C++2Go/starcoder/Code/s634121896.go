
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define macros for convenience
const (
	MOD = 1e9 + 7
	eps = 1e-6
	eps2 = 1e-9
	dosz = 5e5
	SZ = 1 << 18
<<<<<<< HEAD
	PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
=======
	PI = 3.141592653589793
>>>>>>> 98c87cb78a (data updated)
)

// Type definitions for convenience
type (
	ll = int64
	vi = []int
	vvi = [][]int
<<<<<<< HEAD
	vull = []uint64
	vll = []int64
	pii = [2]int
	vpii = []pii
	pll = [2]int64
	vvll = [][]int64
	vc = []byte
=======
	vll = []ll
	vull = []uint
	vvll = [][]ll
	vb = []bool
	vs = []string
	vc = []byte
	vpii = [][2]int
	pqueue = []int
>>>>>>> 98c87cb78a (data updated)
)

// Constants for mathematical operations and limits
const (
	INF = 1e9 + 228
	INFLL = 1e18
	MOD2 = 998244353
)

// Function to optimize input/output
func fast_io() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	fmt.Fscan = func(b *bufio.Reader, a...interface{}) (n int, err error) {
		var a1 []string
		a1 = strings.Split(strings.TrimSpace(fmt.Sscanln(b, a...)), " ")
		n = len(a1)
		for i := 0; i < n; i++ {
			a[i] = a1[i]
		}
		return
	}
	fmt.Fprintln = func(b *bufio.Writer, a...interface{}) (n int, err error) {
<<<<<<< HEAD
		s := fmt.Sprintln(a...)
		n, err = b.Write([]byte(s))
=======
		var a1 []string
		a1 = strings.Split(strings.TrimSpace(fmt.Sprint(a...)), " ")
		n = len(a1)
		for i := 0; i < n; i++ {
			a[i] = a1[i]
		}
		fmt.Fprintln(b, a...)
>>>>>>> 98c87cb78a (data updated)
		return
	}
}

// Main logic to solve the problem
func solve() {
	var n int
	fmt.Fscan(in, &n)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &nums[i])
	}
	dp := make([]int, n + 1)
	dp[0] = 1
	kek := make(map[int]int)
	prev := make(map[int]int)
	for i := 1; i <= n; i++ {
<<<<<<< HEAD
		dp[i] = dp[i - 1] + (prev[nums[i - 1]]!= i - 1 && kek[nums[i - 1]]!= 0)
=======
		dp[i] = dp[i - 1]
		if prev[nums[i - 1]]!= i - 1 {
			dp[i] += kek[nums[i - 1]]
		}
>>>>>>> 98c87cb78a (data updated)
		dp[i] %= MOD
		kek[nums[i - 1]] = dp[i]
		prev[nums[i - 1]] = i
	}
	fmt.Fprintln(out, dp[n])
}

// Main function
func main() {
	fast_io()
	srand(time(NULL))
	q := 1
	// Uncomment the following line to read the number of queries
	// fmt.Fscan(in, &q)
	for ; q > 0; q-- {
		solve()
	}
}

