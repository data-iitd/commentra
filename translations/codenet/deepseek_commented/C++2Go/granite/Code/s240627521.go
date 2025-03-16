
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
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
	max := 1 << 30
	index := -1
	for i := 1; i < n; i++ {
		if max > abs(a[0]-2*a[i]) {
			max = abs(a[0] - 2*a[i])
			index = i
		}
	}
	fmt.Printf("%d %d\n", a[0], a[index])
}

