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
	fmt.Println("Enter two integers separated by a space:")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, " ", ",", -1)
	A, _ := strconv.Atoi(input)
	fmt.Println("Enter another integer:")
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	B, _ := strconv.Atoi(input)
	ans := A - 2*B
	if ans < 0 {
		ans = 0
	}
	fmt.Println(ans)
}

