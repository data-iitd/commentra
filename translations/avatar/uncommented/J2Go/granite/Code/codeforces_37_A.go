
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader))
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(readerReadLine(reader))
		m[val] = m[val] + 1
	}
	max := -1
	for _, v := range m {
		if v > max {
			max = v
		}
	}
	fmt.Println(max, len(m))
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	panic(err)
}

