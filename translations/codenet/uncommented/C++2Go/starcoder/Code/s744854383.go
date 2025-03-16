package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d\n", &a[i])
	}

	idx := 1
	ans := 0
	for i := 0; i < N; i++ {
		if a[i] == idx {
			idx++
		} else {
			ans++
		}
	}

	if idx == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

