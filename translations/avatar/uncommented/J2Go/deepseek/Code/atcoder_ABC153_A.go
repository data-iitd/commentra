package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	var h, a int
	fmt.Sscanf(str, "%d %d", &h, &a)
	num := 0
	for h > 0 {
		h -= a
		num++
	}
	fmt.Println(num)
}
