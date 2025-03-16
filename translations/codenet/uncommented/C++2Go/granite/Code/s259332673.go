
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	h1, _ := strconv.Atoi(read(reader))
	m1, _ := strconv.Atoi(read(reader))
	h2, _ := strconv.Atoi(read(reader))
	m2, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))
	ans := h2*60 + m2 - (h1*60 + m1)
	fmt.Println(ans - k)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

