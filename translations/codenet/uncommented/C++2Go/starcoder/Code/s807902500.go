package main

import "fmt"

func main() {
	var s, t string
	fmt.Scanf("%s\n%s", &s, &t)
	s += s
	fmt.Println(strings.Index(s, t)+1 > 0)
}

