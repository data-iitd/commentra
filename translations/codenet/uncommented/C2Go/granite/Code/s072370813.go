
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var N int
	fmt.Fscanf(in, "%d\n", &N)

	sum := 0
	wa := 0
	A := make([]int, N)
	sa := make([]int, N)
	ans := 0
	shou := 0
	min := 1123456789

	for i := 0; i < N; i++ {
		fmt.Fscanf(in, "%d", &A[i])
		sum += A[i]
		wa += i + 1
	}

	if sum%wa!= 0 {
		ans = 0
	} else {
		shou = sum / wa
		for i := 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou
		}

		for i := 0; i < N-1; i++ {
			if sa[i] <= 0 && sa[i]%N!= 0 {
				ans = 1
				break
			} else {
				ans = 0
			}
		}
	}

	if ans == 1 {
		fmt.Fprint(out, "YES\n")
	} else {
		fmt.Fprint(out, "NO\n")
	}

	out.Flush()
}

