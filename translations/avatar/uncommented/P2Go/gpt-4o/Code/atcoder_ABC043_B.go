package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)
	myStr := ""
	for _, c := range s {
		if c == '0' || c == '1' {
			myStr += string(c)
		} else if c == 'B' && len(myStr) != 0 {
			myStr = myStr[:len(myStr)-1]
		}
	}
	fmt.Println(myStr)
}

// <END-OF-CODE>
