package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, K int
	var S string
	fmt.Scanf("%d %d %s", &N, &K, &S)
	var seg_cnt int
	for i := 0; i < N-1; i++ {
		if S[i]!= S[i+1] {
			seg_cnt++
		}
	}
	cur_happy := N - 1 - seg_cnt
	if 2*K >= seg_cnt {
		fmt.Println(N - 1)
	} else {
		fmt.Println(cur_happy + 2*K)
	}
}

