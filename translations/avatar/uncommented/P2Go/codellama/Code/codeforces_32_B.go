
package main

import "fmt"

func main() {
	s := input()
	result := ""
	i := 0
	for i < len(s) {
		if s[i] == "." {
			result += "0"
		} else {
			i++
			if s[i] == "." {
				result += "1"
			} else {
				result += "2"
			}
		}
		i++
	}
	fmt.Println(result)
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

