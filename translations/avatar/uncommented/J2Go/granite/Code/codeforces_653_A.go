
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscanf(in, "%d\n", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d", &a[i])
	}

	sort.Ints(a)
	a = removeDuplicates(a)

	found := false
	for i := 0; i < len(a)-2; i++ {
		if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
			found = true
			break
		}
	}

	fmt.Fprintf(out, "%s\n", strconv.FormatBool(found))
}

func removeDuplicates(a []int) []int {
	var result []int
	for _, v := range a {
		if!contains(result, v) {
			result = append(result, v)
		}
	}
	return result
}

func contains(a []int, v int) bool {
	for _, x := range a {
		if x == v {
			return true
		}
	}
	return false
}

