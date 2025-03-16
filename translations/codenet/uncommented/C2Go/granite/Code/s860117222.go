
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	a, _ := strconv.ParseInt(nextString(reader), 10, 64)
	b, _ := strconv.ParseInt(nextString(reader), 10, 64)
	c, _ := strconv.ParseInt(nextString(reader), 10, 64)

	d := c - a - b
	if d > 0 && 4*a*b < d*d {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

