package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b int
	var u string
	var str []string
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	str = strings.Split(scanner.Text(), " ")
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d %d", &a, &b)
	scanner.Scan()
	u = scanner.Text()
	if u == str[0] {
		fmt.Println(a-1, b)
	} else {
		fmt.Println(a, b-1)
	}
}

