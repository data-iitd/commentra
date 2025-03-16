
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var N int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &N)
	a := make([]int, N)
	b := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &a[i])
		b[i] = a[i]
	}
	sort.Ints(b)
	frontHalf := b[N/2-1]
	backHalf := b[N/2]
	for i := 0; i < N; i++ {
		if a[i] < backHalf {
			fmt.Println(backHalf)
		} else {
			fmt.Println(frontHalf)
		}
	}
}

