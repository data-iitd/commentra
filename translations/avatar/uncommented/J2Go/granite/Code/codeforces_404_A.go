
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
	arr := make([][]string, n)
	for i := int32(0); i < n; i++ {
		arr[i] = strings.Split(readLine(reader), "")
	}
	a := arr[0][0]
	b := arr[0][1]
	if a == b {
		fmt.Println("NO")
	} else {
		res := true
		for i := int32(0); i < n; i++ {
			for j := int32(0); j < n; j++ {
				if i == j || i+j == n-1 {
					if arr[i][j]!= a {
						res = false
						break
					}
				} else {
					if arr[i][j]!= b {
						res = false
						break
					}
				}
			}
			if!res {
				break
			}
		}
		if res {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

