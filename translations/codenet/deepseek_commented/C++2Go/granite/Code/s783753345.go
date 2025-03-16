
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		a, _ := strconv.Atoi(reader.Scan())
		S := string(reader.Scan())
		b, _ := strconv.Atoi(reader.Scan())
		switch S {
		case "+":
			fmt.Println(a + b)
		case "-":
			fmt.Println(a - b)
		case "*":
			fmt.Println(a * b)
		case "/":
			fmt.Println(a / b)
		case "?":
			return
		}
	}
}

