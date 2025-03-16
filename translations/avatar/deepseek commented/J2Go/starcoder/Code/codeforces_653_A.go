
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
	fmt.Fscanln(reader, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		var value int
		fmt.Fscanln(reader, &value)
		a[i] = value
	}

	a = removeDuplicates(a)
	sort.Ints(a)

	found := false
	for i := 0; i < len(a)-2; i++ {
		if a[i]+1 == a[i+1] && a[i+1]+1 == a[i+2] {
			found = true
			break
		}
	}

	if found {
		fmt.Fprintln(writer, "YES")
	} else {
		fmt.Fprintln(writer, "NO")
	}
}

func removeDuplicates(a []int) []int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}
	var b []int
	for k := range m {
		b = append(b, k)
	}
	return b
}

