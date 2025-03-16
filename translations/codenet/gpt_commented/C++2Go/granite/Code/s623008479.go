
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
	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &l[i])
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < k; i++ {
		ans += l[n-1-i]
	}
	fmt.Println(ans)
}

