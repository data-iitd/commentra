
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

	data := make([]int32, n)

	for i := int32(0); i < n; i++ {
		dataItemTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		dataItem := int32(dataItemTemp)
		data[i] = dataItem
	}

	max := int32(0)
	index := int32(0)

	for i := int32(0); i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}

	a := int32(0)

	for i := int32(0); i < n; i++ {
		if i!= index {
			a += data[i]
		}
	}

	if a > max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
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

