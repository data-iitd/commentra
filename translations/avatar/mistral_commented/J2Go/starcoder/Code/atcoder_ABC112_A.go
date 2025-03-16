
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var strs []string
	var num1, num2 int

	n, _ = strconv.Atoi(readLine())
	if n == 1 {
		fmt.Println("Hello World")
	} else {
		strs = strings.Split(readLine(), " ")
		num1, _ = strconv.Atoi(strs[0])
		num2, _ = strconv.Atoi(strs[1])
		fmt.Println(num1 + num2)
	}
}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(line), "\r\n")
	} else {
		panic(err)
	}
}

