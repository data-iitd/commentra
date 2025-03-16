<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	A := make([]int, N)
	sum := 0
	wa := 0
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
		sum += A[i]
		wa += i + 1
	}
	if sum%wa!= 0 {
		fmt.Println("NO")
		return
	}
	shou := sum / wa
	sa := make([]int, N)
	for i := 0; i < N; i++ {
		sa[i] = A[(i+1)%N] - A[i] - shou
	}
	for i := 0; i < N-1; i++ {
		if sa[i] <= 0 && sa[i]%N == 0 {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}

