
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

	mTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	m := int32(mTemp)

	foods := make([]int32, m)

	for i := int32(0); i < n; i++ {
		kTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		k := int32(kTemp)

		for j := int32(0); j < k; j++ {
			tempTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
			checkError(err)
			temp := int32(tempTemp)

			foods[temp-1]++
		}
	}

	ans := int32(0)

	for _, elem := range foods {
		if elem == n {
			ans++
		}
	}

	fmt.Println(ans)
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

