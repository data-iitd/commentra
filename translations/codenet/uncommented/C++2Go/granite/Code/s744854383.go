
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(read(reader))
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

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

