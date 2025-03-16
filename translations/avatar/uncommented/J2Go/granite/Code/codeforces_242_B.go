
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	INF = 1e9 + 5
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	a := make([]int, n)
	b := make([]int, n)
	left, right := INF, 0
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
		fmt.Fscanf(reader, "%d", &b[i])
		if a[i] < left {
			left = a[i]
		}
		if b[i] > right {
			right = b[i]
		}
	}
	for i := 0; i < n; i++ {
		if a[i] == left && b[i] == right {
			fmt.Println(i + 1)
			return
		}
	}
	fmt.Println(-1)
}

