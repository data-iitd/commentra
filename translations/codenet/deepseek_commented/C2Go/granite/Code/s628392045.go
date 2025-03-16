
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
	h := make([]int32, n)
	for i := int32(0); i < n; i++ {
		hTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		h[i] = int32(hTemp)
	}
	max := int32(-1)
	flag := false
	for i := int32(0); i < n; i++ {
		if h[i] > max {
			max = h[i]
		}
		if max-h[i] >= 2 {
			flag = true
		}
	}
	if flag {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	panic(err)
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

