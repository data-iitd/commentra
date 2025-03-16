package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)

	var i int
	var sum int64 = 0
	var wa int64 = 0
	var A [N]int
	var sa [N]int
	var ans int
	var shou int64

	for i = 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
		sum += int64(A[i])
		wa += int64(i + 1)
	}

	if sum%wa!= 0 {
		ans = 0
	} else {
		shou = sum / wa
		for i = 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou
		}

		for i = 0; i < N-1; i++ {
			if sa[i] <= 0 &&!(sa[i]%N) {
				ans = 1
			} else {
				ans = 0
				break
			}
		}
	}

	if ans == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

