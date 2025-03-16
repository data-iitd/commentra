package main

import (
	"fmt"
	"strings"
)

func main() {
	var pya int
	fmt.Scan(&pya)
	arre := make([]string, 0)

	for pya > 0 {
		pya--
		var inputStr string
		fmt.Scan(&inputStr)
		arre = append(arre, strings.ToLower(inputStr))
	}

	var oString string
	fmt.Scan(&oString)
	lowString := strings.ToLower(oString)

	var letter1 string
	fmt.Scan(&letter1)
	letter1 = string(letter1[0])
	letter1 = strings.ToLower(letter1)

	letter2 := "a"
	if letter1 != "a" {
		letter2 = "b"
	}

	valid := make([]int, len(oString))
	setcito := make(map[int]struct{})

	for _, x := range arre {
		if strings.Contains(lowString, x) {
			wat := 0
			for {
				index := strings.Index(lowString[wat:], x)
				if index < 0 {
					break
				}
				for i := index + wat; i < index+wat+len(x); i++ {
					setcito[i] = struct{}{}
				}
				wat += index + 1
			}
		}
	}

	oStringSlice := []rune(oString)
	for i := range setcito {
		letter := letter1
		if lowString[i] == letter1[0] {
			letter = letter2
		}
		if unicode.IsLower(rune(oStringSlice[i])) {
			oStringSlice[i] = rune(letter[0])
		} else {
			oStringSlice[i] = rune(strings.ToUpper(letter)[0])
		}
	}

	for _, x := range oStringSlice {
		fmt.Print(string(x))
	}
	fmt.Println()
}

// <END-OF-CODE>
