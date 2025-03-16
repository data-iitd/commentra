package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	str := strings.Split(os.Args[1], "")
	dotIndex := 0
	for i := 0; i < len(str); i++ {
		if str[i] == "." {
			dotIndex = i
			break
		}
	}
	if str[dotIndex-1] == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if str[dotIndex+1] > "4" {
		_str := ""
		for i := 0; i < dotIndex; i++ {
			_str += str[i]
		}
		fmt.Println(big.NewInt(0).Add(big.NewInt(0).SetString(_str, 10), big.NewInt(1)).String())
	} else {
		for i := 0; i < dotIndex; i++ {
			fmt.Print(str[i])
		}
		fmt.Println()
	}
}

