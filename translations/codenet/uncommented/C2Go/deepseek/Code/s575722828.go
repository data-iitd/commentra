package main

import (
	"fmt"
)

func main() {
	var S int
	fmt.Scan(&S)
	
	hours := S / 3600
	minutes := (S % 3600) / 60
	seconds := S % 60
	
	fmt.Printf("%d:%d:%d\n", hours, minutes, seconds)
}

