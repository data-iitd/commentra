
package main

import "fmt"

func main() {
	s := "1.2.3.4.5"
	result := ""
	i := 0

	for i < len(s) {
		if s[i] == '.' {
			result += "0"
		} else {
			i++
			if s[i] == '.' {
				result += "1"
			} else {
				result += "2"
			}
		}
		i++
	}

	fmt.Println(result)
}

