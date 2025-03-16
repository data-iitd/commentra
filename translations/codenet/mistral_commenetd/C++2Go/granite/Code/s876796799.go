
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	indA := make([]int, n)
	for i := 0; i < n; i++ {
		indA[a[i]-1] = i
	}

	var ans int64

	usedInds := make([]int, 0)

	for i := 0; i < n; i++ {
		leftBorder := -1
		rightBorder := n

		curInd := indA[i]

		leftIt := sort.Search(len(usedInds), func(j int) bool {
			return usedInds[j] > curInd
		})

		if leftIt > 0 {
			leftIt--
		}

		if leftIt < len(usedInds) {
			leftBorder = usedInds[leftIt]
		}

		rightIt := sort.Search(len(usedInds), func(j int) bool {
			return usedInds[j] >= curInd+1
		})

		if rightIt < len(usedInds) {
			rightBorder = usedInds[rightIt]
		}

		ans += int64(curInd-leftBorder) * int64(rightBorder-curInd) * int64(i+1)

		usedInds = append(usedInds, curInd)
	}

	fmt.Println(ans)
}

