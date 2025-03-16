
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
	result := number * number
	fmt.Println(result)
}

