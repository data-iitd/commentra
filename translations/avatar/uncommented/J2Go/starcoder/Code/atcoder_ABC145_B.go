package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		a, b, str string
		n         int
	)
	fmt.Scanf("%d\n", &n)
	str = strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n'))
	for i := 0; i < n/2; i++ {
		a += string(str[i])
	}
	if str == a+a {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

