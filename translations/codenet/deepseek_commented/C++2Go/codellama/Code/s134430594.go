
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Structure to store the left, right, and value of a ban
type Ban struct {
	l, r, val int
}

// Namespace for sparse table operations
type Sp struct {
	mn [20][200007]int
	pw [200007]int
}

// Initialize the sparse table with the given array
func (sp *Sp) init(a []int) {
	n := len(a)
	for i := 0; i < n; i++ {
		sp.mn[0][i] = a[i]
	}
	for i := 0; i+1 < 20; i++ {
		for j := 0; j+1+(1<<i) <= n; j++ {
			sp.mn[i+1][j] = max(sp.mn[i][j], sp.mn[i][j+(1<<i)])
		}
	}
	sp.pw[1] = 0
	for i := 2; i < 200007; i++ {
		sp.pw[i] = sp.pw[i/2] + 1
	}
}

// Query the sparse table for the minimum value in the range [l, r)
func (sp *Sp) get(l, r int) int {
	r++
	p := sp.pw[r-l]
	return min(sp.mn[p][l], sp.mn[p][r-(1<<p)])
}

// Main function to execute the program
func main() {
	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	dl := make([]int, n)
	for i := range dl {
		if a[i] > i {
			fmt.Println(-1)
			return
		}
		dl[i] = i - a[i]
	}
	ans := 0
	bans := make([]Ban, 0, n)
	for i := 0; i < n; i++ {
		r := i
		for r+1 < n && a[r] == a[r+1] {
			r++
		}
		ans += a[r]
		i = r
		bans = append(bans, Ban{r - a[r], r, r - a[r]})
	}
	sp := new(Sp)
	sp.init(dl)
	for _, t := range bans {
		if sp.get(t.l, t.r) > t.val {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(ans)
}

// 