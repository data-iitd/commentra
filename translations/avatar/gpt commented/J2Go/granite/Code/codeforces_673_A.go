
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

	aTemp := strings.Split(readLine(reader), " ")

	var a []int32

	for i := 0; i < int(n); i++ {
		aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
		checkError(err)
		aItem := int32(aItemTemp)
		a = append(a, aItem)
	}

	result := make([]int32, 1)
	pos := int32(0)
	flag := false

	if a[0] > 15 {
		result[0] = 15
	} else {
		for i := 1; i < int(n); i++ {
			if a[i]-a[i-1] > 15 {
				pos = i - 1
				flag = true
				break
			}
		}

		if flag {
			result[0] = a[pos] + 15
		} else {
			result[0] = a[n-1] + 15
		}
	}

	if result[0] > 90 {
		result[0] = 90
	}

	fmt.Println(result[0])
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

