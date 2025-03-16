
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Define the first hour and minute variables from user input
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	h1, _ := strconv.Atoi(strings.Split(string(line), ":")[0])
	m1, _ := strconv.Atoi(strings.Split(string(line), ":")[1])

	// Add the hour to the minute value
	m1 += h1 * 60

	// Define the second hour and minute variables from user input
	line, _, _ = reader.ReadLine()
	h2, _ := strconv.Atoi(strings.Split(string(line), ":")[0])
	m2, _ := strconv.Atoi(strings.Split(string(line), ":")[1])

	// Add the hour to the minute value for the second set of variables
	m2 += h2 * 60

	// Calculate the difference between the total minutes of the first and second sets of variables
	m2 = m1 - m2

	// Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
	m2 %= 1440

	// Print the result in the format of hours and minutes
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}
