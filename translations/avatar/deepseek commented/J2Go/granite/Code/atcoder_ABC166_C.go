
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N, _ := strconv.Atoi(read(reader))
	M, _ := strconv.Atoi(read(reader))

	H := make([]int64, N)
	ans := make([]bool, N)

	for i := 0; i < N; i++ {
		H[i], _ = strconv.ParseInt(read(reader), 10, 64)
		ans[i] = true
	}

	for i := 0; i < M; i++ {
		temp1, _ := strconv.Atoi(read(reader))
		temp2, _ := strconv.Atoi(read(reader))

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

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}

	return string(str)
}

