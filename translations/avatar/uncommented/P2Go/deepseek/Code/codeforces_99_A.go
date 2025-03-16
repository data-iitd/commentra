package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, ".")
	firstPart := parts[0]
	secondPart := parts[1]
	lastChar := string(firstPart[len(firstPart)-1])
	i, _ := strconv.Atoi(secondPart)

	if lastChar == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if lastChar != "9" && i < 5 {
		fmt.Println(firstPart)
	} else {
		num, _ := strconv.Atoi(firstPart)
		num += 1
		fmt.Println(strconv.Itoa(num))
	}
}

