

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

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &l[i])
	}

	sort.Ints(l)

	for _, v := range l {
		if v+1 < len(l) && l[v+1] == v+1 {
			if v+2 < len(l) && l[v+2] == v+2 {
				fmt.Println("YES")
				return
			}
		}
	}

	fmt.Println("NO")
}

