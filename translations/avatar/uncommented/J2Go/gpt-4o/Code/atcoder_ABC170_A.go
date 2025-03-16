package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	inputArray := strings.Fields(input)
	result := 0

	for _, str := range inputArray {
		result++
		if str == "0" {
			break
		}
	}

	fmt.Println(result)
}

// <END-OF-CODE>
