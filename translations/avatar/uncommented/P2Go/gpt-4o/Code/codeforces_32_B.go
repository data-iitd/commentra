package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scan(&s)
	result := ""
	i := 0
	for i < len(s) {
		if s[i] == '.' {
			result += "0"
		} else {
			i++
			if i < len(s) && s[i] == '.' {
				result += "1"
			} else {
				result += "2"
			}
		}
		i++
	}
	fmt.Println(result)
}

// <END-OF-CODE>
