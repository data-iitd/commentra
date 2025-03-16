
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a, b, c, d int
	for i := 0; i < 4; i++ {
		input, _ := reader.ReadString('\n')
		value, _ := strconv.Atoi(input)
		switch i {
		case 0:
			a = value
		case 1:
			b = value
		case 2:
			c = value
		case 3:
			d = value
		}
	}
	area := (a - c) * (b - d)
	fmt.Println(area)
}

