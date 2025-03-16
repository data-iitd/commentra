
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
	input_array := strings.Split(reader.ReadLine(), " ")
	result := 0
	for _, str := range input_array {
		result += 1
		if str == "0" {
			break
		}
	}
	fmt.Println(result)
}

