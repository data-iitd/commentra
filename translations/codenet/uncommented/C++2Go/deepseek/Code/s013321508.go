package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, M int
	fmt.Fscan(reader, &N, &M)

	L := make([]int, 100000)
	for i := 0; i < N; i++ {
		var l int
		fmt.Fscan(reader, &l)
		L[i] = l
	}

	sort.Ints(L)

	for i := 0; i < M; i++ {
		maxL := L[len(L)-1]
		if maxL == 0 {
			break
		}

		maxL /= 2
		idx := sort.Search(len(L), func(j int) bool {
			return L[j] >= maxL
		})
		L = append(L[:idx], append([]int{maxL}, L[idx:]...)...)
		L = L[:len(L)-1]
	}

	var ans int64 = 0
	for _, v := range L {
		ans += int64(v)
	}

	fmt.Fprintln(writer, ans)
}

