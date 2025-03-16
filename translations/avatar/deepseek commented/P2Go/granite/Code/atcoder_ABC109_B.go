
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

	s := make(map[string]int32)

	l := make([]string, n)

	for i := int32(0); i < n; i++ {
		l[i] = readLine(reader)

		s[l[i]]++

		if s[l[i]] >= 2 {
			fmt.Println("No")
			return
		}

		if i!= 0 && l[i-1][len(l[i-1])-1]!= l[i][0] {
			fmt.Println("No")
			return
		}
	}

	fmt.Println("Yes")
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

