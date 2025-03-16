package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	buf := make([]byte, 512)
	n, err := reader.Read(buf)
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}
	len := n
	if len > 0 {
		fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])
	}
}
