package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	s += s
	fmt.Println(s.Find(t) != -1)
}

