package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n, q int
	var S []int
	var T []int
	var c int
	fmt.Scanf("%d", &n)
	S = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &S[i])
	}
	fmt.Scanf("%d", &q)
	T = make([]int, q)
	for i := 0; i < q; i++ {
		fmt.Scanf("%d", &T[i])
	}
	sort.Ints(S)
	for i := 0; i < q; i++ {
		if sort.SearchInts(S, T[i])!= -1 {
			c++
		}
	}
	fmt.Printf("%d\n", c)
}

