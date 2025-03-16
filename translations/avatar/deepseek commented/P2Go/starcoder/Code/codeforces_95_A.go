
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var (
		arre []string
		pya  int
		oString string
		lowString string
		letter1 string
		letter2 string
		valid []int
		setcito map[int]bool
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &pya)
	for i := 0; i < pya; i++ {
		var x string
		fmt.Fscan(reader, &x)
		arre = append(arre, x)
	}
	fmt.Fscan(reader, &oString)
	lowString = strings.ToLower(oString)
	letter1 = string(oString[0])
	letter2 = "a"
	if letter1!= "a" {
		letter2 = "b"
	}
	valid = make([]int, len(oString))
	setcito = make(map[int]bool)
	for _, x := range arre {
		if strings.Contains(lowString, x) {
			wat := 0
			for {
				index := strings.Index(lowString, x, wat)
				if index < 0 {
					break
				}
				for i := index; i < index + len(x); i++ {
					setcito[i] = true
				}
				wat = index + 1
		}
	}
	oString = strings.ToLower(oString)
	for i := range oString {
		if setcito[i] {
			if oString[i] >= 'a' && oString[i] <= 'z' {
				oString = strings.Replace(oString, string(oString[i]), string(letter1), 1)
			} else {
				oString = strings.Replace(oString, string(oString[i]), string(letter2), 1)
			}
		}
	}
	fmt.Println(oString)
}

