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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	input_array := strings.Split(input, " ")

	result := 0
	for _, str := range input_array {
		result += 1
		if str == "0" {
			break
		}
	}

	fmt.Fprintln(writer, result)
}

