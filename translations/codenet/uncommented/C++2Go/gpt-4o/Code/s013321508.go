package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	sort.Ints(L)

	for i := 0; i < M; i++ {
		maxL := L[len(L)-1]
		if maxL == 0 {
			break
		}

		maxL /= 2
		L = append(L[:len(L)-1], maxL) // Remove the last element and append maxL
		sort.Ints(L)                   // Re-sort the slice after insertion
	}

	var ans int64 = 0
	for _, v := range L {
		ans += int64(v)
	}

	fmt.Println(ans)
}

// <END-OF-CODE>
