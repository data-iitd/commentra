package main

import (
	"fmt"
	"strings"
)

func main() {
	var stdin string
	fmt.Scanln(&stdin)
	s := stdin
	result := "No"
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		result = "Yes"
	}
	fmt.Println(result)
}

// <END-OF-CODE>
