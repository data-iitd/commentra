package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
	"time"
)

// Define macros for convenience
// #define DEBUG
// #define fi first
// #define se second
// #define pqueue priority_queue
// #define pb(x) push_back(x)
// #define endl '\n'
// #define all(x) x.begin(), x.end()
// #define int long long // Use long long for integer types
// #define mk(a, b) make_pair(a, b)

// Type definitions for convenience
type Int = int64
type Uint = uint64
type Float = float64

// Constants for mathematical operations and limits
const INF = 1e9 + 228
const INFLL = 1e18
const MOD = 1e9 + 7
const eps = 1e-6
const eps2 = 1e-9
const MOD2 = 998244353
const dosz = 5e5
const SZ = 1 << 18
const PI = math.Atan2(0, -1)

// Function to optimize input/output
func fast_io() {
	println("fast_io function not implemented in Go")
}

// Main logic to solve the problem
func solve() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}
	
	// Dynamic programming array to store results
	dp := make([]int, n + 1)
	dp[0] = 1
	kek := make(map[int]int)
	prev := make(map[int]int)
	
	// Fill the dynamic programming array
	for i := 1; i <= n; i++ {
		// Update dp[i] based on previous values and occurrences
		if prev[nums[i - 1]] != i - 1 {
			dp[i] = dp[i - 1] + kek[nums[i - 1]]
		} else {
			dp[i] = dp[i - 1]
		}
		dp[i] %= MOD
		kek[nums[i - 1]] = dp[i]
		prev[nums[i - 1]] = i
	}
	
	fmt.Println(dp[n])
}

// Main function
func main() {
	fast_io()
	rand.Seed(time.Now().UnixNano())
	fmt.Println(math.Round(123.456789*100) / 100)
	q := 1
	for q > 0 {
		solve()
		q--
	}
}

