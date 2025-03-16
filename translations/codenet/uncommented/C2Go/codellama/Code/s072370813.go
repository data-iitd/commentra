package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	var i int
	var sum int64 = 0
	var wa int64 = 0
	var A [N]int
	var sa [N]int
	var ans int
	var shou int
	var min int64 = 1123456789

	for i = 0; i < N; i++ {
		fmt.Scan(&A[i])
		sum += int64(A[i])
		wa += int64(i + 1)
	}

	if sum%wa == 0 {
		shou = int(sum / wa)
		for i = 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou
		}

		for i = 0; i < N-1; i++ {
			if sa[i] <= 0 && !(sa[i]%N) {
				ans = 1
			} else {
				ans = 0
				break
			}
		}
	} else {
		ans = 0
	}

	if ans == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

