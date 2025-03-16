
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
	var N int64
	fmt.Fscanf(reader, "%d\n", &N)
	var x int64
	fmt.Fscanf(reader, "%d\n", &x)
	sweet := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Fscanf(reader, "%d\n", &sweet[i])
	}
	sort.Slice(sweet, func(i, j int) bool {
		return sweet[i] < sweet[j]
	})
	num := int64(0)
	for i := int64(0); i < N; i++ {
		if x-sweet[num] >= 0 {
			x = x - sweet[num]
			num++
		} else {
			break
		}
	}
	if num == N && x > 0 {
		num -= 1
	}
	fmt.Println(num)
}

