
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	N, _ := strconv.Atoi(read(reader))
	D, _ := strconv.Atoi(read(reader))

	ans := N / (D*2 + 1)
	rem := N % (D*2 + 1)

	if rem!= 0 {
		ans = ans + 1
	}

	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

