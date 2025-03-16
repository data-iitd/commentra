package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &m)

	foods := make([]int, m)

	for i := 0; i < n; i++ {
		var k int
		fmt.Fscan(reader, &k)

		for j := 0; j < k; j++ {
			var temp int
			fmt.Fscan(reader, &temp)
			temp--

			foods[temp]++
		}
	}

	ans := 0
	for _, elem := range foods {
		if elem == n {
			ans++
		}
	}

	fmt.Println(ans)
}

