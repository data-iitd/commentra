

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

	for i := int32(0); i < n; i++ {
		cakeTemp := readLine(reader)
		cake[i] = cakeTemp
	}

	happiness := int32(0)
	chocCount := int32(0)
	nfat := int32(1)

	for i := int32(0); i < n; i++ {
		for j := int32(0); j < n; j++ {
			if string(cake[i][j]) == "C" {
				chocCount++
			}
		}
		if chocCount > int32(1) {
			for i := chocCount; i > int32(1); i-- {
				nfat *= i
			}
			happiness += nfat / int32(2)
		}
		nfat = int32(1)
		chocCount = int32(0)
	}

	posCount := int32(0)

	for j := int32(0); j < n; j++ {
		chocCount = int32(0)
		for i := int32(0); i < n; i++ {
			if string(cake[i][j]) == "C" {
				chocCount++
			}
		}
		if chocCount > int32(1) {
			for i := chocCount; i > int32(1); i-- {
				nfat *= i
			}
			happiness += nfat / int32(2)
		}
		nfat = int32(1)
		chocCount = int32(0)
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

