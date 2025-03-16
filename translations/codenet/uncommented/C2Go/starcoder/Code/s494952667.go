package main

import "fmt"

func main() {
	var str string
	fmt.Scanf("%s", &str)
	for i := len(str) - 1; i >= 0; i-- {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
}

