package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	s += s
	if s.Find(t) == -1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

