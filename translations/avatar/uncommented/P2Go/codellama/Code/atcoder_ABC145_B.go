package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	if n%2 != 0 {
		fmt.Println("No")
	} else if s[:n/2] == s[n/2:] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

