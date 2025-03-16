
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	var a int
	fmt.Fscanf(reader, "%d\n", &a)

	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &s[i])
	}

	sort.Ints(s)

	sum := 0
	for i := n - 1; i > n-a-1; i-- {
		sum += s[i]
	}

	fmt.Println(sum)
}

