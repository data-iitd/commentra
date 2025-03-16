

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var pya int
	fmt.Scan(&pya)
	arre := make([]string, pya)
	for i := 0; i < pya; i++ {
		fmt.Scan(&arre[i])
		arre[i] = strings.ToLower(arre[i])
	}
	var oString string
	fmt.Scan(&oString)
	lowString := strings.ToLower(oString)
	var letter1, letter2 rune
	fmt.Scan(&letter1)
	letter2 = 'a'
	if letter1 == 'a' {
		letter2 = 'b'
	}
	valid := make([]int, len(oString))
	setcito := make(map[int]bool)
	for _, x := range arre {
		wat := 0
		for {
			index := strings.Index(lowString, x, wat)
			if index < 0 {
				break
			}
			for i := index; i < index+len(x); i++ {
				setcito[i] = true
			}
			wat = index + 1
		}
	}
	oString = strings.ToLower(oString)
	for i := range oString {
		if setcito[i] {
			letter := letter1
			if oString[i]!= letter1 {
				letter = letter2
			}
			if oString[i] >= 'a' && oString[i] <= 'z' {
				oString = oString[:i] + string(letter) + oString[i+1:]
			} else {
				oString = oString[:i] + string(unicode.ToUpper(letter)) + oString[i+1:]
			}
		}
	}
	fmt.Println(oString)
}

