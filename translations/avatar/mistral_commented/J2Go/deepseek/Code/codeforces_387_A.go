package main

import (
	"fmt"
	"time"
)

func main() {
	// Read the first time string from the console and split it into hour and minute parts
	var s, t string
	fmt.Scan(&s, &t)

	// Split the time strings into hour and minute parts
	splitS := split(s, ":")
	splitT := split(t, ":")

	// Create LocalTime objects `x` and `y` from the hour and minute parts of the first and second time strings, respectively
	hourS, _ := time.ParseDuration(splitS[0] + "h")
	minuteS, _ := time.ParseDuration(splitS[1] + "m")
	hourT, _ := time.ParseDuration(splitT[0] + "h")
	minuteT, _ := time.ParseDuration(splitT[1] + "m")

	// Create time.Time objects from the duration objects
	x := time.Now().Add(hourS + minuteS)
	y := time.Now().Add(hourT + minuteT)

	// Calculate the difference between the two times
	difference := x.Sub(y)

	// Print the result of subtracting the second time from the first time, which is the difference between the two times in hours and minutes
	fmt.Println(difference)
}

// Helper function to split a string by a delimiter
func split(s, delimiter string) []string {
	result := []string{}
	for {
		index := s.Index(delimiter)
		if index == -1 {
			result = append(result, s)
			break
		}
		result = append(result, s[:index])
		s = s[index+len(delimiter):]
	}
	return result
}

