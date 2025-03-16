
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

	var N, K int
	fmt.Fscanf(reader, "%d %d\n", &N, &K)

	v := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &v[i])
	}

	// ceil((N-1) / (K-1))
	count := ((N - 1) + ((K - 1) - 1)) / (K - 1)
	fmt.Println(count)
}
