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
	str := strings.Split(strings.TrimSpace(reader.ReadLine()), " ")
	a, _ := strconv.Atoi(str[0])
	b, _ := strconv.Atoi(str[1])
	u := strings.TrimSpace(reader.ReadLine())
	if u == str[0] {
		fmt.Println(a-1, " ", b)
	} else {
		fmt.Println(a, " ", b-1)
	}
}

