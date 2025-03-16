
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N := readInt()
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = readInt()
	}
	i := 0
	ans := 0
	count := 0
	for i < N-1 {
		if A[i] == A[i+1] {
			count++
			if count%2!= 0 {
				ans++
			}
		} else {
			count = 0
		}
		i++
	}
	fmt.Println(ans)
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

