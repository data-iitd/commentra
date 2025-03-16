
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	fmt.Println("Enter k, n, w")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	k, n, w := strings.Split(input, " ")

	if 1 <= int(k) && int(w) <= 1000 {
		total := 0
		for i := 1; i <= int(w); i++ {
			total += i * int(k)
		}
		if total > int(n) {
			fmt.Println(total - int(n))
		} else {
			fmt.Println(0)
		}
	}
}

