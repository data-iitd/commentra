package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')

	s = s + s

	if index := strings.Index(s, t); index != -1 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

