
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

	absA := make([]int32, len(a))
	copy(absA, a)

	for i := 0; i < len(a); i++ {
		if absA[i] < 0 {
			absA[i] = -absA[i]
		}
	}

	ans := int64(0)

	min := int64(absA[0])

	for _, e := range absA {
		ans += int64(e)
		if min > int64(e) {
			min = int64(e)
		}
	}

	numNegative := int32(0)

	for _, e := range a {
		if e < 0 {
			numNegative++
		}
	}

	if numNegative%2!= 0 {
		ans -= min * 2
	}

	fmt.Println(ans)
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

