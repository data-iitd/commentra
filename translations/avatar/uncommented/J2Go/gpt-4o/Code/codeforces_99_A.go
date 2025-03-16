package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)

	dotIndex := strings.Index(input, ".")
	if dotIndex == -1 {
		return // No dot found, exit
	}

	if input[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if input[dotIndex+1] > '4' {
		_str := input[:dotIndex]
		num := new(big.Int)
		num.SetString(_str, 10)
		num.Add(num, big.NewInt(1))
		fmt.Println(num.String())
	} else {
		fmt.Println(input[:dotIndex])
	}
}

// <END-OF-CODE>
