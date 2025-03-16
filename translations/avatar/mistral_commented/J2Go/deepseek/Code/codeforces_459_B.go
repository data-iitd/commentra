package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	N := parseInt(in.Text())
	A := make([]int, N)

	for n := 0; n < N; n++ {
		in.Scan()
		A[n] = parseInt(in.Text())
	}

	sort.Ints(A)

	min, max := A[0], A[N-1]
	mins, maxs := 0, 0

	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	if min == max {
		result := int64((max - min + 1) * mins)
		result -= int64(mins * (mins - 1) / 2)
		fmt.Fprintln(out, result)
	} else {
		result := int64((max - min) * mins * maxs)
		fmt.Fprintln(out, result)
	}
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}
