package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n, _ := strconv.Atoi(in.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		a[i], _ = strconv.Atoi(in.Text())
	}

	sort.Ints(a)
	set := make(map[int]bool)
	for _, value := range a {
		set[value] = true
	}

	keys := make([]int, 0, len(set))
	for k := range set {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	found := false
	for i := 0; i < len(keys)-2; i++ {
		if keys[i]+1 == keys[i+1] && keys[i+1]+1 == keys[i+2] {
			found = true
			break
		}
	}

	if found {
		fmt.Fprintln(out, "YES")
	} else {
		fmt.Fprintln(out, "NO")
	}
}

