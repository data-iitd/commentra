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
	arre := []string{}
	reader := bufio.NewReader(os.Stdin)
	for pya > 0 {
		pya--
		line, _ := reader.ReadString('\n')
		arre = append(arre, strings.ToLower(strings.TrimSpace(line)))
	}
	oString, _ := reader.ReadString('\n')
	lowString := strings.ToLower(oString)
	var letter1, letter2 string
	fmt.Scanf("%c", &letter1)
	letter1 = strings.ToLower(letter1)
	letter2 = "b"
	if letter1 != "a" {
		letter2 = "a"
	}
	valid := make([]int, len(oString))
	setcito := make(map[int]bool)
	for _, x := range arre {
		if strings.Contains(lowString, x) {
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
	}
	oStringSlice := []rune(oString)
	for i := range oStringSlice {
		if setcito[i] {
			letter := letter1
			if lowString[i] == letter1[0] {
				letter = letter2
			}
			if oStringSlice[i] >= 'a' && oStringSlice[i] <= 'z' {
				oStringSlice[i] = rune(letter[0])
			} else {
				oStringSlice[i] = rune(strings.ToUpper(letter)[0])
			}
		}
	}
	for _, x := range oStringSlice {
		fmt.Printf("%c", x)
	}
	fmt.Println()
}

