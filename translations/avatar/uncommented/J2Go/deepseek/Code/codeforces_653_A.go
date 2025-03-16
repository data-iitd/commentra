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
	uniqueA := removeDuplicates(a)

	found := false
	for i := 0; i < len(uniqueA); i++ {
		if i+1 < len(uniqueA) && i+2 < len(uniqueA) {
			if uniqueA[i]+1 == uniqueA[i+1] && uniqueA[i+1]+1 == uniqueA[i+2] {
				found = true
				break
			}
		}
	}

	if found {
		fmt.Fprintln(out, "YES")
	} else {
		fmt.Fprintln(out, "NO")
	}
}

func removeDuplicates(arr []int) []int {
	sort.Ints(arr)
	unique := []int{}
	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i] != arr[i-1] {
			unique = append(unique, arr[i])
		}
	}
	return unique
}

