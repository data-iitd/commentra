package main

import (
	"fmt"
	"strings"
)

func main() {
	var N, K int
	var S string
	fmt.Scan(&N, &K, &S)

	seg_cnt := 0
	for i := 0; i < N-1; i++ {
		if S[i] != S[i+1] {
			seg_cnt++
		}
	}

	cur_happy := N - 1 - seg_cnt
	if 2*K >= seg_cnt {
		ans := N - 1
		fmt.Println(ans)
	} else {
		ans := cur_happy + 2*K
		fmt.Println(ans)
	}
}

