
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	qTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	q := int32(qTemp)
	for q > 0 {
		nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		n := int32(nTemp)
		x := int32(log2(n))
		s := -1*(1<<uint(x+1)) + 2 + (n*(n+1))/2 - (1 << uint(x+1))
		fmt.Println(s)
		q--
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

func log2(n int32) int32 {
	var x int32
	for n > 0 {
		x++
		n = n >> 1
	}
	return x - 1
}

