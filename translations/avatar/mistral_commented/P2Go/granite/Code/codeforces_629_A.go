

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	cake := make([]string, n)

	var happiness int32 = 0
	var chocCount int32 = 0
	var nfat int32 = 1

	for i := int32(0); i < n; i++ {
		cake[i] = readLine(reader)

		for j := int32(0); j < int32(len(cake[i])); j++ {
			if string(cake[i][j]) == "C" {
				chocCount++
			}
		}

		if chocCount > 1 {
			nfat = 1
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
		}

		chocCount = 0
	}

	posCount := int32(0)
	for j := int32(0); j < n; j++ {
		for i := int32(0); i < n; i++ {
			if string(cake[i][j]) == "C" {
				chocCount++
			}
		}

		if chocCount > 1 {
			nfat = 1
			for i := chocCount; i > chocCount-2; i-- {
				nfat *= i
			}
			happiness += nfat / 2
		}

		chocCount = 0
	}

	fmt.Println(happiness)
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

