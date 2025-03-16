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
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	str := []rune(input)
	dotIndex := 0

	for i := 0; i < len(str); i++ {
		if str[i] == '.' {
			dotIndex = i
			break
		}
	}

	if str[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if int(str[dotIndex+1]-'0') > 4 {
		_str := string(str[:dotIndex])
		num, _ := strconv.Atoi(_str)
		fmt.Println(strconv.Itoa(num + 1))
	} else {
		fmt.Println(string(str[:dotIndex]))
	}
}

