
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func binPrint(x int, bits int) {
	for i := bits - 1; i >= 0; i-- {
		fmt.Printf("%d", x&(1<<i))
	}
	fmt.Println()
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	a, _ := strconv.Atoi(readNext(reader))
	b, _ := strconv.Atoi(readNext(reader))

	binPrint(a&b, 32)
	binPrint(a|b, 32)
	binPrint(a^b, 32)
}

func readNext(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

