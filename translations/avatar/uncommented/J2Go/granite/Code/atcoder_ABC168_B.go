
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

	kTemp, err := reader.ReadString('\n')
	checkError(err)
	k, err := strconv.Atoi(strings.TrimSpace(kTemp))
	checkError(err)

	sTemp, err := reader.ReadString('\n')
	checkError(err)
	s := strings.TrimSpace(sTemp)

	if len(s) <= k {
		fmt.Println(s)
	} else {
		fmt.Println(s[:k] + "...")
	}
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

