
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Taking input in the format of 'HH:MM' and splitting it into hours and minutes
	h1, m1 := splitTime(input())

	// Converting hours to minutes and adding it to the minutes part
	m1 += h1 * 60

	// Taking another input in the same format and converting it into total minutes since midnight
	h2, m2 := splitTime(input())
	m2 += h2 * 60

	// Calculating the difference in total minutes between the two times
	m2 = m1 - m2

	// Ensuring the result is within a 24-hour period by using modulo operation
	m2 %= 1440

	// Printing the result in 'HH:MM' format
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

func splitTime(s string) (int, int) {
	h, m := strings.Split(s, ":")
	h1, _ := strconv.Atoi(h)
	m1, _ := strconv.Atoi(m)
	return h1, m1
}

