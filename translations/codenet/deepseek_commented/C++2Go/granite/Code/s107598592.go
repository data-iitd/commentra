
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	X := make([]int, N)
	Y := make([]int, N)
	for i := 0; i < N; i++ {
		X[i], _ = strconv.Atoi(reader.ReadLine())
		Y[i] = X[i]
	}
	sort.Ints(Y)
	y := Y[N/2]
	for i := 0; i < N; i++ {
		if X[i] < y {
			fmt.Println(y)
		} else {
			fmt.Println(y - 1)
		}
	}
}
