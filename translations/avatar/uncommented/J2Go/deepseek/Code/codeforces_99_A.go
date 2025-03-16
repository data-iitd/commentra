package main

import (
	"fmt"
	"strconv"
)

func main() {
	var str string
	fmt.Scanln(&str)
	dotIndex := 0
	for i := 0; i < len(str); i++ {
		if str[i] == '.' {
			dotIndex = i
			break
		}
	}
	if str[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if str[dotIndex+1] >= '5' {
		fmt.Println(strconv.Atoi(str[:dotIndex-1]) + 1)
	} else {
		fmt.Println(str[:dotIndex])
	}
}

