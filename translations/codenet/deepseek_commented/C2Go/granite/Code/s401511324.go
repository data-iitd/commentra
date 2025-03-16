
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
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(read(reader))
	}
	cnt := 0
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				if l[i]+l[j] > l[k] {
					cnt++
				} else {
					break
				}
			}
		}
	}
	fmt.Println(cnt)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

