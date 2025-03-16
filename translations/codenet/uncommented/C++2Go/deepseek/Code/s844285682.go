package main

import (
	"fmt"
)

func main() {
	var a int
	fmt.Scan(&a)
	
	hours := a / (60 * 60)
	minutes := a % (60 * 60) / 60
	seconds := a % (60 * 60) % 60
	
	fmt.Printf("%02d:%02d:%02d\n", hours, minutes, seconds)
}

