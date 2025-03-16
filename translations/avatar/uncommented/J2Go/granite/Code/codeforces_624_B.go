
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
	ans := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &ans[i])
	}
	sort.Sort(sort.Int64Slice(ans))
	count := int64(0)
	for i := n - 1; i >= 0; i-- {
		if ans[i] < ans[i+1] {
			count += ans[i]
		} else {
			for ans[i] >= ans[i+1] {
				ans[i]--
			}
			if ans[i] > 0 {
				count += ans[i]
			}
		}
	}
	fmt.Println(count)
}

