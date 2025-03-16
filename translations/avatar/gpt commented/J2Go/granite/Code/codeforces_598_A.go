
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	qTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	q := int32(qTemp)

	for qTab := 0; qTab < int(q); qTab++ {
		nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		n := int32(nTemp)

		s := int64(-1 * (1 << (int(n) + 1)) + 2 + (int64(n) * (int64(n) + 1)) / 2 - (1 << (int(n) + 1)))

		fmt.Println(s)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

