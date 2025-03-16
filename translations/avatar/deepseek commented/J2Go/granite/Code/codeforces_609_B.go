

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	arr := make([]int, n)
	gen := make([]int, 11)

	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &arr[i])
		gen[arr[i]]++
	}

	var ans int64

	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i!= k {
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	fmt.Println(ans / 2)
}

