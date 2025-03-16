
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	a, _ := strconv.Atoi(nextString(reader))
	b, _ := strconv.Atoi(nextString(reader))
	c, _ := strconv.Atoi(nextString(reader))

	if b > a*c {
		fmt.Println(c)
	} else {
		fmt.Println(b / a)
	}
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

