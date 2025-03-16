
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
	fmt.Println(solve(reader))
}

func solve(reader *bufio.Reader) int {
	N, _ := strconv.Atoi(read(reader))
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		arr[i], _ = strconv.Atoi(read(reader))
	}
	sum := 0
	sort.Ints(arr)
	for i := 0; i < N; i++ {
		if arr[i] <= arr[0] {
			sum++
		}
	}
	return sum
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

