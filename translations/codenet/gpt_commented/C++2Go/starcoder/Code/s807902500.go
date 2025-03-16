package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')
	s = s + s
	if strings.Contains(s, t) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

