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
	input_array := strings.Split(input, " ")
	result := 0

	for _, str := range input_array {
		result++
		if str == "0" {
			break
		}
	}

	fmt.Println(result)
}

