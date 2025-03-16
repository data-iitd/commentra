
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
		input, _ := reader.ReadString('\n')
		if input[0] == '0' {
			break
		}
		sum := 0
		for _, char := range input {
			if char == '\n' {
				break
			}
			digit, _ := strconv.Atoi(string(char))
			sum += digit
		}
		fmt.Println(sum)
	}
}

// END-OF-CODE