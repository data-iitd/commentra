
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.ParseInt(read(reader), 10, 64)
	a := make([]int64, n)
	count := make([]int64, n)

	for i := int64(1); i < n; i++ {
		a[i], _ = strconv.ParseInt(read(reader), 10, 64)
	}

	for i := int64(0); i < n; i++ {
		count[i] = 0
	}

	for i := int64(1); i < n; i++ {
		count[a[i]-1]++
	}

	for i := int64(0); i < n; i++ {
		fmt.Println(count[i])
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

