
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input string from the user
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')

	// Find the index of the dot ('.') in the string
	dotIndex := strings.Index(str, ".")

	// Check if the character before the dot is '9'
	if str[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else {
		// If the character before the dot is not '9', check the digit after the dot
		if str[dotIndex+1] > '4' {
			// Increment the number before the dot by 1 and print the result
			_str := str[:dotIndex]
			fmt.Println(strconv.FormatInt(int64(new(big.Int).Add(new(big.Int).SetString(_str, 10), big.NewInt(1))), 10))
		} else {
			// If the digit after the dot is 4 or less, print the number before the dot without any changes
			fmt.Println(str[:dotIndex])
		}
	}
}

