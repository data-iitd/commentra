
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	sort.Ints(a)
	for i := 0; i < n-1; i++ {
		if a[i] == a[i+1] {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}

