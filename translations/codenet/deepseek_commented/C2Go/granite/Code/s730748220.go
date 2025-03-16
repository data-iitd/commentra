
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(text)
	result := 24 + (24 - n)
	fmt.Println(result)
}

