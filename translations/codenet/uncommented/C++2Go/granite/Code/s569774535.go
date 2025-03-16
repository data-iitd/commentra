
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readerReadLine(reader))
	}

	ans := 0
	ok := true
	for ok {
		for i := 0; i < n; i++ {
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			} else {
				a[i] /= 2
			}
		}
		ans++
	}

	fmt.Println(ans)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

