
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(nTemp, 10, 64)
	checkError(err)

	s := ""
	for i := int64(1); i <= 1000; i++ {
		s += strconv.FormatInt(i, 10)
	}

	fmt.Println(string(s[n-1]))
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

