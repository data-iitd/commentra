
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(readerReadLine(reader))
	b, _ := strconv.Atoi(readerReadLine(reader))
	c, _ := strconv.Atoi(readerReadLine(reader))

	if a+b >= c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

