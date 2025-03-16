
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

	countTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	count := int32(countTemp)

	result := printIsland(n, count)

	fmt.Println(result)
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

func printIsland(n int32, count int32) string {
	a := (n + 1) / 2
	b := n / 2
	max := a*a + b*b

	if count > max {
		return "NO"
	}

	result := "YES\n"

	for i := int32(0); i < n; i++ {
		for j := int32(0); j < n; j++ {
			if (i+j)%2 == 0 && count > 0 {
				result += "L"
				count--
			} else {
				result += "S"
			}
		}
		result += "\n"
	}

	return result
}

// 