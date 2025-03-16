
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
	i := 1
	ans := 0
	for 10*i <= N {
		ans += 10*i - 10*(i-1)
		i += 2
	}
	ans += max(0, N-10*(i-1)+1)
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

