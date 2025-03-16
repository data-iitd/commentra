

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

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	q := make([][]string, n)

	for i := int32(0); i < n; i++ {
		q[i] = strings.Split(readLine(reader), " ")
	}

	count := int32(0)

	for i := int32(0); i < n; i++ {
		for j := int32(0); j < n; j++ {
			if j == i {
				continue
			} else if q[i][0] == q[j][len(q[j])-1] {
				count++
			} else {
				continue
			}
		}
	}

	fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}

	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

