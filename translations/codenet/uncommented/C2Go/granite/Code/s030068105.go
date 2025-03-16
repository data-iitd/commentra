
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

	for i := 0; i < int(n); i++ {
		dataItemTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		dataItem := int32(dataItemTemp)
		data[i] = dataItem
	}

	max := int32(0)
	index := int32(0)
	for i := 0; i < int(n); i++ {
		if data[i] > max {
			max = data[i]
			index = int32(i)
		}
	}

	a := int32(0)
	for i := 0; i < int(n); i++ {
		if i!= int(index) {
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

