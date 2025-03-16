

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
	mp := make(map[int32]int32)
	for i := 0; i < int(n); i++ {
		arrItemTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		arrItem := int32(arrItemTemp)
		mp[arrItem]++
	}
	max := int32(0)
	for _, v := range mp {
		if v > max {
			max = v
		}
	}
	fmt.Println(max, len(mp))
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

