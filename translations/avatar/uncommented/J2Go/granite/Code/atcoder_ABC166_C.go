
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadLine()[2:])
	M, _ := strconv.Atoi(reader.ReadLine()[2:])
	H := make([]int, N)
	ans := make([]bool, N)
	for i := 0; i < N; i++ {
		H[i], _ = strconv.Atoi(reader.ReadLine()[2:])
		ans[i] = true
	}
	for i := 0; i < M; i++ {
		temp1, _ := strconv.Atoi(reader.ReadLine()[2:])
		temp2, _ := strconv.Atoi(reader.ReadLine()[2:])
		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false
		} else {
			ans[temp1-1] = false
			ans[temp2-1] = false
		}
	}
	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++
		}
	}
	fmt.Println(ans2)
}

