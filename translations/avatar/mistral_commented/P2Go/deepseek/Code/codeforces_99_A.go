package main

import (
	"fmt"
	"strings"
)

func main() {
	var l string
	fmt.Scanln(&l)

	l = strings.TrimRight(l, ".")
	parts := strings.Split(l, ".")

	s := parts[0]
	p := parts[1]

	lastChar := string(s[len(s)-1])

	if lastChar == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if lastChar != "9" && p[0] < '5' {
		fmt.Println(s)
	} else {
		num, _ := fmt.Println(strconv.Itoa(int(s) + 1))
		// Handle the case where the incremented number might have leading zeros
		// This is a simplified approach and might need adjustments based on exact requirements
	}
}
