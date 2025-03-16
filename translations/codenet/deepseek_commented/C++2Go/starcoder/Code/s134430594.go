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

// Namespace for sparse table operations
type Sp struct {
<<<<<<< HEAD
	mn [20][]int
	pw []int
=======
	mn   [][]int
	pw   []int
	n, m int
>>>>>>> 98c87cb78a (data updated)
}

// Initialize the sparse table with the given array
func (s *Sp) init(a []int) {
<<<<<<< HEAD
	n := len(a)
	for i := 0; i < n; i++ {
		s.mn[0][i] = a[i]
	}
	for i := 0; i+1 < 20; i++ {
		for j := 0; j+(1<<uint(i+1)) <= n; j++ {
			s.mn[i+1][j] = max(s.mn[i][j], s.mn[i][j+(1<<uint(i))])
		}
	}
	s.pw = make([]int, n)
	s.pw[0] = 0
	for i := 1; i < n; i++ {
=======
	s.n = len(a)
	s.m = 1 << (len(a) - 1)
	s.mn = make([][]int, len(a))
	s.pw = make([]int, s.n)
	for i := 0; i < s.n; i++ {
		s.mn[0][i] = a[i]
	}
	for i := 0; i < len(a)-1; i++ {
		for j := 0; j+1<<i <= s.n; j++ {
			s.mn[i+1][j] = max(s.mn[i][j], s.mn[i][j+1<<i])
		}
	}
	s.pw[1] = 0
	for i := 2; i < s.n; i++ {
>>>>>>> 98c87cb78a (data updated)
		s.pw[i] = s.pw[i/2] + 1
	}
}

// Query the sparse table for the minimum value in the range [l, r)
func (s *Sp) get(l, r int) int {
	r++
	p := s.pw[r-l]
<<<<<<< HEAD
	return min(s.mn[p][l], s.mn[p][r-(1<<uint(p))])
}

// Main function to execute the program
func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read input
	n, _ := strconv.Atoi(readLine(reader))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readLine(reader))
	}

	// Compute the answer
=======
	return min(s.mn[p][l], s.mn[p][r-(1<<p)])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanln(reader, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &a[i])
	}
	dl := make([]int, n)
	for i := 0; i < n; i++ {
		if a[i] > i {
			fmt.Println(-1)
			return
		}
		dl[i] = i - a[i]
	}
>>>>>>> 98c87cb78a (data updated)
	ans := 0
	bans := make([]Ban, n)
	for i := 0; i < n; i++ {
		r := i
		for r+1 < n && a[r]+1 == a[r+1] {
			r++
		}
		ans += a[r]
<<<<<<< HEAD
		bans[i] = Ban{r - a[r], r, r - a[r]}
		i = r
	}

	// Initialize the sparse table
	sp := Sp{}
	sp.init(bans)

	// Check if the bans are valid
	for i := 0; i < n; i++ {
		if sp.get(bans[i].l, bans[i].r) > bans[i].val {
=======
		i = r
		bans[i] = Ban{r - a[r], r, r - a[r]}
	}
	s := Sp{}
	s.init(dl)
	for _, t := range bans {
		if s.get(t.l, t.r) > t.val {
>>>>>>> 98c87cb78a (data updated)
			fmt.Println(-1)
			return
		}
	}
<<<<<<< HEAD

	// Print the answer
	fmt.Println(ans)
}

// ReadLine reads a line from the given reader
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return strings.TrimRight(string(str), "\r\n")
}

// min returns the minimum of the two given integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// max returns the maximum of the two given integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// END-OF-CODE

=======
	fmt.Println(ans)
}

>>>>>>> 98c87cb78a (data updated)
