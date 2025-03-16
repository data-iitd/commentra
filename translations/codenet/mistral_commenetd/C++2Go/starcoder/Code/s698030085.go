<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	b, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	if (a + b) % 2 == 0 {
		fmt.Println((a + b) / 2)
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

