
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := fmt.Fscanf(reader, "%d\n", &n)
	checkError(err)

	ans := make([]int64, n)

	for i := 0; i < int(n); i++ {
		ansTemp, err := fmt.Fscanf(reader, "%d\n", &ansTemp)
		checkError(err)
		ans[i] = int64(ansTemp)
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	count := int64(ans[n-1])

	for i := n - 2; i >= 0; i-- {
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

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

