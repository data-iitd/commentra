package main

import (
	"fmt"
	"time"
)

func main() {
	// Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
	var s, t string
	fmt.Scan(&s, &t)
	
	// Parsing the input strings into time.Time objects for the first and second time
	x, _ := time.Parse("15:04", s)
	y, _ := time.Parse("15:04", t)
	
	// Calculating the difference between the two times
	diff := x.Sub(y)
	
	// Printing the result
	fmt.Println(diff)
}
