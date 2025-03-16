
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := strconv.ParseInt(nextString(reader), 10, 64)
	y, _ := strconv.ParseInt(nextString(reader), 10, 64)
	if int(math.Abs(float64(x-y))) <= 1 {
		fmt.Println("Brown")
	} else {
		fmt.Println("Alice")
	}
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

