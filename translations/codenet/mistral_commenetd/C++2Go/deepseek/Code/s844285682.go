package main

import (
	"fmt"
)

func main() {
	var a int

	fmt.Print("Enter the number of seconds: ")
	fmt.Scan(&a)

	hours := a / (60 * 60)
	minutes := (a % (60 * 60)) / 60
	seconds := (a % (60 * 60)) % 60

	fmt.Println(hours, ":", minutes, ":", seconds)
}

