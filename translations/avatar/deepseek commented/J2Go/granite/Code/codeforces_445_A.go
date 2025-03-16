
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
	input := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	nTemp, err := strconv.ParseInt(input[0], 10, 64)
	checkError(err)
	n := int32(nTemp)
	mTemp, err := strconv.ParseInt(input[1], 10, 64)
	checkError(err)
	m := int32(mTemp)
	result := make([]string, n)
	for i := int32(0); i < n; i++ {
		result[i] = readLine(reader)
	}
	for i := int32(0); i < n; i++ {
		for j := int32(0); j < m; j++ {
			if result[i][j] == '-' {
				fmt.Print("-")
			} else {
				if (i+j)%2 == 0 {
					fmt.Print("B")
				} else {
					fmt.Print("W")
				}
			}
		}
		fmt.Println()
	}
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

