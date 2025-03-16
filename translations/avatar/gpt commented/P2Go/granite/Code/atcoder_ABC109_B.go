
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

	s := make(map[string]int32)

	l := make([]string, n)

	for i := int32(0); i < n; i++ {
		l[i] = readLine(reader)

		s[l[i]]++

		if s[l[i]] > 1 {
			fmt.Println("No")
			return
		}
	}

	f := "Yes"

	for i := int32(0); i < n-1; i++ {
		if l[i][len(l[i])-1]!= l[i+1][0] {
			f = "No"
			break
		}
	}

	fmt.Println(f)
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

