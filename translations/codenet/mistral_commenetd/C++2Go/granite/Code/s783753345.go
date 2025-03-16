
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
		a, _ := strconv.Atoi(reader.ReadLine()[0:1])
		S := reader.ReadLine()[1:2]
		b, _ := strconv.Atoi(reader.ReadLine()[0:1])
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
