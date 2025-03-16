
package main

import (
	"fmt"
	"strings"
)

func main() {
	var pya int
	fmt.Scan(&pya)
	arre := make([]string, pya)
	for i := 0; i < pya; i++ {
		fmt.Scan(&arre[i])
	}

	var oString string
	fmt.Scan(&oString)
	lowString := strings.ToLower(oString)

	var letter1, letter2 string
	fmt.Scan(&letter1)
	letter2 = "a"
	if letter1 != "a" {
		letter2 = "b"
	}

	valid := make([]int, len(oString))
	setcito := make(map[int]bool)

	for _, x := range arre {
		for i := 0; i < len(lowString); i++ {
			if lowString[i:i+len(x)] == x {
				setcito[i] = true
			}
		}
	}

	for i := 0; i < len(oString); i++ {
		if setcito[i] {
			if oString[i] >= 'a' && oString[i] <= 'z' {
				oString = oString[:i] + letter1 + oString[i+1:]
			} else {
				oString = oString[:i] + letter1.ToUpper() + oString[i+1:]
			}
		}
	}

	fmt.Println(oString)
}

