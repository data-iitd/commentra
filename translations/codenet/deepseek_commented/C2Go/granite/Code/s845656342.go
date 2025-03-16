
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.Atoi(text)

	if number == 1 {
		fmt.Println(0)
	} else {
		fmt.Println(1)
	}
}

