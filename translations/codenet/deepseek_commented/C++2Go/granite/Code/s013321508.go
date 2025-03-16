
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

	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &l[i])
	}

	sort.Ints(l)

	for i := 0; i < m; i++ {
		maxL := l[len(l)-1]
		if maxL == 0 {
			break
		}

		maxL /= 2
		itr := sort.SearchInts(l, maxL)
		l = append(l[:itr], append([]int{maxL}, l[itr:]...)...)
		l = l[:len(l)-1]
	}

	sum := 0
	for _, v := range l {
		sum += v
	}

	fmt.Println(sum)
}

