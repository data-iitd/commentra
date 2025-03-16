
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	idx := 1
	ans := 0
	for i := 0; i < n; i++ {
		if a[i] == idx {
			idx++
		} else {
			ans++
		}
	}

	if idx == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

