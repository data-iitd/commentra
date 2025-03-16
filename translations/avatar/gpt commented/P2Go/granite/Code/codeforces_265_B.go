
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

	l := make([]int32, n)

	for i := int32(0); i < n; i++ {
		lTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		l[i] = int32(lTemp)
	}

	ans := n - 1

	last := int32(0)

	for i := int32(0); i < n; i++ {
		ans += int32(abs(int(last-l[i]))) + 1

		last = l[i]
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

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

