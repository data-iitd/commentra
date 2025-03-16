package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1
	mid := (upp - low + 1) / 2

	if upp - low < 0 {
		return 0
	} else if li[from] >= target {
		return 0
	} else if li[upp] < target {
		return upp - low + 1
	}

	for upp - low > 1 {
		if li[mid] >= target {
			upp = mid
		} else {
			low = mid
		}
		mid = (upp - low + 1) / 2
	}

	return low - from + 1
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N := 0
	fmt.Sscanf(scanner.Text(), "%d", &N)

	L := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &L[i])
	}

	sort.Ints(L)

	count := 0

	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			a := L[i]
			b := L[j]

			res := find(L, j+1, a+b)

			count += res
		}
	}

	fmt.Println(count)
}

