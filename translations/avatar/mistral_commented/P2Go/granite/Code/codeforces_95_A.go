
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
	}
	oString := ""
	fmt.Scan(&oString)
	letter1 := strings.ToLower(string(oString[0]))
	letter2 := "a"
	if letter1!= "a" {
		letter2 = "b"
	}
	valid := make([]int, len(oString))
	setcito := make(map[int]bool)
	for _, x := range arre {
		if strings.Contains(strings.ToLower(oString), strings.ToLower(x)) {
			for i := strings.Index(oString, x); i < len(oString); i++ {
				setcito[i] = true
			}
		}
	}
	oString = string(oString)
	for i := range oString {
		if setcito[i] {
			letter := letter1
			if strings.ToLower(string(oString[i]))!= letter1 {
				letter = letter2
			}
			if strings.ToLower(string(oString[i])) == strings.ToLower(letter) {
				letter = strings.ToUpper(letter)
			}
			oString = oString[:i] + letter + oString[i+1:]
		}
	}
	fmt.Println(oString)
}

