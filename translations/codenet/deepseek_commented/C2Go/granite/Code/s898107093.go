
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

	taro := int32(0)
	hanako := int32(0)

	for i := int32(0); i < n; i++ {
		tTemp := readLine(reader)

		hTemp := readLine(reader)

		t := strings.Split(tTemp, " ")

		h := strings.Split(hTemp, " ")

		if t[0] < h[0] {
			hanako += 3
		} else if t[0] > h[0] {
			taro += 3
		} else {
			taro += 1
			hanako += 1
		}
	}

	fmt.Printf("%d %d\n", taro, hanako)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), "\r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

