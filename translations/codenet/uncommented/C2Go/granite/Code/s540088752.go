
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {

	N := readInt()

	A := make([]int, N+1)
	B := make([]int, N)

	for i := 0; i < N+1; i++ {
		A[i] = readInt()
	}

	for i := 0; i < N; i++ {
		B[i] = readInt()
	}

	ans := 0

	for i := 0; i < N; i++ {

		//site i
		if A[i] >= B[i] {
			ans = ans + B[i]
			A[i] = A[i] - B[i]
			B[i] = 0
		} else {
			ans = ans + A[i]
			B[i] = B[i] - A[i]
			A[i] = 0
		}

		//site i + 1
		if A[i+1] >= B[i] {
			ans = ans + B[i]
			A[i+1] = A[i+1] - B[i]
			B[i] = 0
		} else {
			ans = ans + A[i+1]
			B[i] = B[i] - A[i+1]
			A[i+1] = 0
		}
	}

	fmt.Println(ans)

}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

