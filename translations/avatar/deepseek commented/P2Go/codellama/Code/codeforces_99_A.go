
package main

import (
	"fmt"
	"strings"
)

func main() {
	var l string
	fmt.Scanln(&l)
	l = strings.Split(l, ".")
	s := strings.Split(l[0], "")
	p := strings.Split(l[1], "")
	i, _ := strconv.Atoi(p[0])

	if s[len(s)-1] == "9" {
		fmt.Println("GOTO Vasilisa.")
	} else if s[len(s)-1] != "9" && i < 5 {
		fmt.Println(strings.Join(s, ""))
	} else {
		s = strings.Join(s, "")
		s = strconv.Itoa(strconv.Atoi(s) + 1)
		fmt.Println(s)
	}
}

