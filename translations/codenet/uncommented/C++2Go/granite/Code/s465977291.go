
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	d, _ := strconv.Atoi(read(reader))

	a := float64(d*2 + 1)
	fmt.Println(int(math.Ceil(float64(n) / a)))
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

