
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
	K, _ := strconv.Atoi(read(reader))

	A := make([]int, N+1)
	for i := 1; i <= N; i++ {
		A[i], _ = strconv.Atoi(read(reader))
	}

	cur := 1
	dic := make([]int, N+1)
	flg := false

	for i := 1; i <= K; i++ {
		if dic[cur] < 0 || flg {
			dic[cur] = i
			cur = A[cur]
		} else if!flg {
			tmp := K - (dic[cur] - 1)
			tmp %= i - dic[cur]
			i = K - tmp
			flg = true
		}
	}

	fmt.Println(cur)
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}

	return string(str)
}

