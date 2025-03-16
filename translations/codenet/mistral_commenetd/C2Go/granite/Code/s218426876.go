

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
	for {
		fmt.Print("Enter a string of digits separated by spaces or newline: ")
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		if text == "0" {
			break
		}
		sum := 0
		for _, char := range text {
			if char =='' {
				continue
			}
			digit, _ := strconv.Atoi(string(char))
			sum += digit
		}
		fmt.Printf("Sum of digits in previous string: %d\n", sum)
	}
}

// 