package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	solve(n)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}

func solve(n int) {
	fmt.Println((n/3)*2 + (n%3 == 0 ? 0 : 1))
}

