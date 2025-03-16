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
	s := strings.Split(parts[0], "")
	p := strings.Split(parts[1], "")

	i, _ := strconv.Atoi(p[0])

	if s[len(s)-1] == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if s[len(s)-1] != "9" && i < 5 {
		result := strings.Join(s, "")
		fmt.Println(result)
	} else {
		result := strings.Join(s, "")
		num, _ := strconv.Atoi(result)
		num++
		fmt.Println(num)
	}
}

// <END-OF-CODE>
