
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter A: ")
	text, _ := reader.ReadString('\n')
	A, _ := strconv.Atoi(strings.TrimSpace(text))
	fmt.Print("Enter B: ")
	text, _ = reader.ReadString('\n')
	B, _ := strconv.Atoi(strings.TrimSpace(text))
	ans := A - 2*B
	if ans < 0 {
		ans = 0
	}
	fmt.Println(ans)
}

