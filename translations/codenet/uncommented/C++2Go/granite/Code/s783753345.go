
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
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		fields := strings.Fields(string(line))
		a, _ := strconv.Atoi(fields[0])
		b, _ := strconv.Atoi(fields[2])
		switch fields[1] {
		case "+":
			fmt.Println(a + b)
		case "-":
			fmt.Println(a - b)
		case "*":
			fmt.Println(a * b)
		case "/":
			fmt.Println(a / b)
		}
		if fields[1] == "?" {
			break
		}
	}
}
