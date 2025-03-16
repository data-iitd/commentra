
package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	s += s
	if s == t {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

