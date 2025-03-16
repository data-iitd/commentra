package main

import (
	"fmt"
	"math"
)

const (
	BIG      = 2000000007
	VERYBIG  = 20000000000000007
	MOD      = 1000000007
	FOD      = 998244353
	N_MAX    = 1048576
)

type hwll struct {
	a int64
	b int64
}

type hwllc struct {
	a int64
	b int64
	c int64
}

type hwreal struct {
	a float64
	b float64
}

var (
	n, m int64
	h, w int64
	k    int64
	q    int64
	va, vb, vc, vd, ve, vf int64
	ua, ub, uc, ud, ue, uf uint64
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte
	a, b, c [N_MAX]int64
	s       string
)

func main() {
	// Initialize variables
	n = 4
	m = 0

	// Read input values
	fmt.Scan(&s)

	// Initialize arrays
	for i := 0; i < N_MAX; i++ {
		a[i] = 0
		b[i] = 0
		c[i] = 0
	}

	// Read input values
	for i := int64(0); i < n; i++ {
		fmt.Scan(&b[i])
	}

	// Read input values
	for i := int64(0); i < m; i++ {
		fmt.Scan(&c[i])
	}

	// Read input value
	fmt.Scan(&q)

	// Call the solve function
	solve()
}

// Main function implementation
func solve() {
	var result int64 = 1
	var pcnt int64 = 0
	cnt := [3]int64{}

	for i := int64(0); i < n*3; i++ {
		var v int64
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}

		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			result *= pcnt
			pcnt--
			result %= FOD
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {
			if (cnt[(v+1)%3]+cnt[(v+2)%3]) > cnt[v] {
				result *= (cnt[(v+1)%3] + cnt[(v+2)%3]) - cnt[v]
				result %= FOD
				pcnt++
			}
			cnt[v]++
		}
	}

	for i := int64(1); i <= n; i++ {
		result = (result * i) % FOD
	}

	fmt.Println(result)
}

// Helper functions can be added here if needed

// <END-OF-CODE>
