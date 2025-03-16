package main

import (
	"bufio"
	"fmt"
	"os"
)

func cout(str string) {
	fmt.Println(str)
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var a, b, str string
	var n int

	fmt.Scan(&n)
	reader.ReadString('\n')

	str, _ = reader.ReadString('\n')

	for i := 0; i < n/2; i++ {
		a += string(str[i])
	}

	if str == a+a {
		cout("Yes")
	} else {
		cout("No")
	}
}

