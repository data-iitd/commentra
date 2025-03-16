
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
	arrTemp := strings.Split(readLine(reader), " ")
	var arr []int32
	for i := 0; i < int(n); i++ {
		arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
		checkError(err)
		arrItem := int32(arrItemTemp)
		arr = append(arr, arrItem)
	}
	sum := int32(0)
	for i := 0; i < int(n); i++ {
		sum += arr[i]
	}
	c := int32(0)
	sb := strings.Builder{}
	for i := 0; i < int(n); i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb.WriteString(strconv.Itoa(i + 1))
			sb.WriteString(" ")
		}
	}
	fmt.Println(c)
	fmt.Println(sb.String())
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

