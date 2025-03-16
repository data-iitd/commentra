package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)
	in.Split(bufio.ScanWords)

	in.Scan()
	N := parseInt(in.Text())
	A := make([]int, N)
	for n := 0; n < N; n++ {
		in.Scan()
		A[n] = parseInt(in.Text())
	}
	sort.Ints(A)
	min := A[0]
	max := A[N-1]
	var mins, maxs int64
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}
	if min == max {
		fmt.Fprintln(pw, (max-min), mins*(mins-1)/2)
	} else {
		fmt.Fprintln(pw, (max-min), mins*maxs)
	}
	pw.Flush()
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

