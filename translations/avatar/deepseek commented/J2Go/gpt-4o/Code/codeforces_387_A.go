package main

import (
	"fmt"
	"strconv"
	"strings"
	"time"
)

func main() {
	// Step 1: Read two times from the user, split by colon and convert to time.Time objects
	var input string
	fmt.Scanln(&input)
	times := strings.Split(input, " ")
	s := strings.Split(times[0], ":")
	t := strings.Split(times[1], ":")

	h1, _ := strconv.Atoi(s[0])
	m1, _ := strconv.Atoi(s[1])
	x := time.Date(0, 1, 1, h1, m1, 0, 0, time.UTC)

	h2, _ := strconv.Atoi(t[0])
	m2, _ := strconv.Atoi(t[1])
	y := time.Date(0, 1, 1, h2, m2, 0, 0, time.UTC)

	// Step 2: Calculate the difference between the two times
	diff := x.Sub(y)
	fmt.Println(diff)
}

// <END-OF-CODE>
