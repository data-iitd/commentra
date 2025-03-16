
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N int64
	var x int64
	fmt.Fscanf(reader, "%d\n", &N)
	fmt.Fscanf(reader, "%d\n", &x)

	srimeList := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Fscanf(reader, "%d\n", &srimeList[i])
	}

	costList := make([][]int64, N)
	for i := int64(0); i < N; i++ {
		costList[i] = make([]int64, N)
		costList[i][0] = srimeList[i]
		for castNum := int64(1); castNum < N; castNum++ {
			costList[i][castNum] = int64(min(int(costList[i][castNum-1]), int(srimeList[(i-castNum+N)%N])))
		}
	}

	result := make([]int64, N)
	for i := int64(0); i < N; i++ {
		temp := i * x
		for _, cost := range costList[i] {
			temp += cost
		}
		result[i] = temp
	}

	fmt.Println(min(result...))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// END-OF-CODE