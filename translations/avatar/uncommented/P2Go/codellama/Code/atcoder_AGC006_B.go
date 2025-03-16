
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N, X int
	fmt.Scan(&N, &X)
	fmt.Println(N, X)
	var xs []int
	if X == 1 || X == N*2-1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
		if X == N*2-2 {
			for i := N - 1; i <= X+2; i++ {
				xs = append(xs, i)
			}
			for i := 1; i < N-1; i++ {
				xs = append(xs, i)
			}
		} else {
			for i := 1; i < X-1; i++ {
				xs = append(xs, i)
			}
			for i := X + 3; i < N*2; i++ {
				xs = append(xs, i)
			}
		}
		for _, x := range xs {
			fmt.Println(x)
		}
	}
}

