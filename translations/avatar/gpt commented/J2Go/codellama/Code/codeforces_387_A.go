package main

import (
	"fmt"
	"time"
)

func main() {
	// Creating a Scanner object to read input from the console
	sc := new(Scanner)

	// Reading two time inputs in "HH:MM" format and splitting them into hours and minutes
	s := sc.next().split(":")
	t := sc.next().split(":")

	// Creating LocalTime objects from the input strings for the first and second time
	x := time.LocalTime.of(s[0], s[1])
	y := time.LocalTime.of(t[0], t[1])

	// Calculating the difference between the two times and printing the result
	fmt.Println(x.minusHours(y.getHour()).minusMinutes(y.getMinute()))
}

