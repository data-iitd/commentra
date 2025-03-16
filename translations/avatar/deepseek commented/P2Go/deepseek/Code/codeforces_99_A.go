package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	parts := strings.Split(input, ".")
	firstPart := parts[0]
	secondPart := parts[1]
	firstChar := string(firstPart[len(firstPart)-1])
	secondInt := int(secondPart[0] - '0')

	if firstChar == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if firstChar != "9" && secondInt < 5 {
		fmt.Println(firstPart)
	} else {
		incremented := strconv.Itoa(int(firstPart[0]-'0') + 1)
		fmt.Println(incremented)
	}
}

