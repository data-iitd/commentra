
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	N := readInt()
	X := make([]int, N)
	Y := make([]int, N)
	for i := 0; i < N; i++ {
		X[i] = readInt()
		Y[i] = X[i]
	}
	sort.Ints(Y)
	y := Y[N/2]
	for i := 0; i < N; i++ {
		if X[i] < Y[N/2] {
			fmt.Println(Y[N/2])
		} else {
			fmt.Println(Y[N/2-1])
		}
	}
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

