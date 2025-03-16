
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	T, _ := strconv.Atoi(readerReadLine(reader))
	S, _ := strconv.Atoi(readerReadLine(reader))
	q, _ := strconv.Atoi(readerReadLine(reader))
	previous := S
	answer := 0
	for previous < T {
		answer++
		previous *= q
	}
	fmt.Println(answer)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

