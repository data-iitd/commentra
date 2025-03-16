
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
	mTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	m := int32(mTemp)
	arrs := make([]string, n)
	for i := int32(0); i < n; i++ {
		arrs[i] = readLine(reader)
	}
	length := make([]int32, n)
	index := int32(0)
	returnDex := int32(0)
	for _, tmp := range arrs {
		dexG := strings.Index(tmp, "G")
		dexS := strings.Index(tmp, "S")
		if dexG > dexS {
			returnDex = -1
			break
		}
		length[index] = int32(dexS - dexG)
		index++
	}
	set := make(map[int32]bool)
	for _, len := range length {
		set[len] = true
	}
	if returnDex == -1 {
		fmt.Println(returnDex)
	} else {
		fmt.Println(len(set))
	}
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

