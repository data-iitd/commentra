
package main

import (
	"fmt"
	"sort"
	"math"
	"container/list"
	"strconv"
	"strings"
	"os"
	"bufio"
	"io"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	L := make([]int, 100000)
	var l int
	for i := 0; i < N; i++ {
		fmt.Scan(&l)
		L[i] = l
	}

	sort.Ints(L)

	var max_L int
	var itr int
	for i := 0; i < M; i++ {
		max_L = L[len(L)-1]
		if max_L == 0 {
			break
		}

		max_L /= 2
		itr = sort.SearchInts(L, max_L)
		L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)
		L = L[:len(L)-1]
	}

	var ans int64
	for _, v := range L {
		ans += int64(v)
	}

	fmt.Println(ans)
}

