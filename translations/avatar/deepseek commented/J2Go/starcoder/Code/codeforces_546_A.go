package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var pandu, vundu, urdu, c int64
	var input string
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)

	input, _ = reader.ReadString('\n')
	pandu, _ = strconv.ParseInt(strings.TrimSpace(input), 10, 64)

	input, _ = reader.ReadString('\n')
	vundu, _ = strconv.ParseInt(strings.TrimSpace(input), 10, 64)

	input, _ = reader.ReadString('\n')
	urdu, _ = strconv.ParseInt(strings.TrimSpace(input), 10, 64)

	for i := int64(1); i <= urdu; i++ {
		c += i * pandu
	}

	if c < vundu {
		fmt.Println("0")
	} else {
		fmt.Println(c - vundu)
	}
}

