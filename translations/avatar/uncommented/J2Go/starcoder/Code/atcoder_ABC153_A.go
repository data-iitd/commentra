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
	str, _ := reader.ReadString('\n')
	str = strings.Split(str, " ")
	h, _ := strconv.Atoi(str[0])
	a, _ := strconv.Atoi(str[1])
	num := 0
	for i := 1; h > 0; i++ {
		h = h - a
		num++
	}
	fmt.Println(num)
}

