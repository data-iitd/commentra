

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Taking input in the format of 'HH:MM' and splitting it into hours and minutes
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	parts := strings.Split(string(line), ":")
	h1, _ := strconv.Atoi(parts[0])
	m1, _ := strconv.Atoi(parts[1])

	// Converting hours to minutes and adding it to the minutes part
	m1 += h1 * 60

	// Taking another input in the same format and converting it into total minutes since midnight
	line, _, _ = reader.ReadLine()
	parts = strings.Split(string(line), ":")
	h2, _ := strconv.Atoi(parts[0])
	m2, _ := strconv.Atoi(parts[1])
	m2 += h2 * 60

	// Calculating the difference in total minutes between the two times
	m2 = m1 - m2

	// Ensuring the result is within a 24-hour period by using modulo operation
	m2 %= 1440

	// Printing the result in 'HH:MM' format
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}
