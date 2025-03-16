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
	letter1 := string(oString[0])
	letter2 := "a"
	if letter1 != "a" {
		letter2 = "b"
	}
	valid := make([]int, len(oString))
	setcito := make(map[int]bool)
	for _, x := range arre {
		if strings.Contains(lowString, x) {
			wat := 0
			for {
				index := strings.Index(lowString, x)
				if index < 0 {
					break
				}
				for i := index; i < index+len(x); i++ {
					setcito[i] = true
				}
				wat = index + 1
			}
		}
	}
	oString = []rune(oString)
	for i := range setcito {
		letter := letter1
		if lowString[i] != letter1 {
			letter = letter2
		}
		oString[i] = rune(letter)
	}
	for _, x := range oString {
		fmt.Print(string(x))
	}
	fmt.Println()
}

