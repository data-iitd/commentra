
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

	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	arr := make([][]rune, n)
	for i := int64(0); i < n; i++ {
		arrTemp, err := reader.ReadString('\n')
		checkError(err)
		arr[i] = []rune(strings.TrimSpace(arrTemp))
	}

	a := arr[0][0]
	b := arr[0][1]

	if a == b {
		fmt.Println("NO")
		return
	}

	res := true
	for i := int64(0); i < n; i++ {
		for j := int64(0); j < n; j++ {
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
	}

	if res {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

