
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	k int
	a []int
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	k, _ = strconv.Atoi(read(reader))

	a = make([]int, k)
	for i := 0; i < k; i++ {
		a[i], _ = strconv.Atoi(read(reader))
	}

	max, min := 3, 2
	if a[k-1]!= 2 {
		fmt.Println(-1)
		return
	}

	for i := k - 2; i >= 0; i-- {
		if a[i] > max {
			fmt.Println(-1)
			return
		} else {
			max = ((max / a[i]) + 1) * a[i] - 1
			if min%a[i]!= 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		if max <= min {
			fmt.Println(-1)
			return
		}
	}

	fmt.Printf("%d %d\n", min, max)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

