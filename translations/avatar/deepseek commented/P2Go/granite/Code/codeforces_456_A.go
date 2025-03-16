

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

	m := make([][]int32, n)

	for i := int32(0); i < n; i++ {
		mTemp := strings.Split(readLine(reader), " ")

		m[i] = make([]int32, 2)

		for j := int32(0); j < 2; j++ {
			mTempItem, err := strconv.ParseInt(mTemp[j], 10, 64)
			checkError(err)
			m[i][j] = int32(mTempItem)
		}
	}

	sort.Slice(m, func(i, j int) bool {
		return m[i][1] > m[j][1]
	})

	a := m[0]

	for i := 1; i < int(n); i++ {
		if m[i][1] > a[1] {
			fmt.Println("Happy Alex")
			break
		}

		a = m[i]
	}

	if i == int(n) {
		fmt.Println("Poor Alex")
	}
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

