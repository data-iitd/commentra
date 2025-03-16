
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	rw = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}
	indA := make([]int, n)
	for i := 0; i < n; i++ {
		indA[a[i]-1] = i
	}
	usedInds := make([]bool, n)
	var ans int64
	for i := 0; i < n; i++ {
		var leftBorder, rightBorder int
		curInd := indA[i]
		leftIt := sort.Search(n, func(j int) bool {
			return usedInds[j] && j <= curInd
		})
		if leftIt == 0 {
			leftBorder = -1
		} else {
			leftBorder = leftIt - 1
		}
		rightIt := sort.Search(n, func(j int) bool {
			return usedInds[j] && j >= curInd
		})
		if rightIt == n {
			rightBorder = n
		} else {
			rightBorder = rightIt
		}
		ans += int64((curInd - leftBorder)) * int64((rightBorder - curInd)) * int64(i+1)
		usedInds[curInd] = true
	}
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

