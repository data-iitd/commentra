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

	var N int
	fmt.Fscan(reader, &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	sort.Ints(A)
	min := A[0]
	max := A[N-1]
	mins := 0
	maxs := 0
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}
	if min == max {
		fmt.Fprintln(writer, (max-min), " ", mins*(mins-1)/2)
	} else {
		fmt.Fprintln(writer, (max-min), " ", mins*maxs)
	}
}

