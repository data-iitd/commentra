
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

	mTemp := strings.Split(readLine(reader), " ")

	possible := true

	for i := 0; i < len(mTemp); i++ {
		m := mTemp[i]
		count := 0
		for j := 0; j < len(mTemp); j++ {
			if mTemp[j] == m {
				count++
			}
		}
		if count >= (n/2)+1 {
			possible = false
			break
		}
	}

	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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
