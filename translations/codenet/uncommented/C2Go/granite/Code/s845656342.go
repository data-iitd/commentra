
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a number:")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.Atoi(text)

	if number == 1 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

