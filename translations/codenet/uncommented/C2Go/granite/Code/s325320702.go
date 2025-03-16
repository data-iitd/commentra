

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	l, _ := strconv.Atoi(readerReadLine(reader))
	r, _ := strconv.Atoi(readerReadLine(reader))
	d, _ := strconv.Atoi(readerReadLine(reader))
	ans := 0
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

func readerReadLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	} else {
		panic(err)
	}
}