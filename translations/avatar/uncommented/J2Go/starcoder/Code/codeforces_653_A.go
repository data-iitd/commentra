package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		var value int
		fmt.Fscan(reader, &value)
		a[i] = value
	}
	sort.Ints(a)
	a = unique(a)
	found := false
	for i := 0; i < len(a); i++ {
		if i+1 < len(a) && i+2 < len(a) {
			if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
				found = true
			}
		}
	}
	if found {
		fmt.Fprintln(writer, "YES")
	} else {
		fmt.Fprintln(writer, "NO")
	}
}

func unique(a []int) []int {
	var result []int
	for i := 0; i < len(a); i++ {
		if i == 0 || a[i]!= a[i-1] {
			result = append(result, a[i])
		}
	}
	return result
}

