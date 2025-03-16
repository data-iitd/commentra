
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the maximum level from user input
	maxLevel, _ := strconv.Atoi(read(reader))

	// Read the levels completed by player X and convert them to a list of integers
	x := readNNumbers(reader, maxLevel)

	// Read the levels completed by player Y and convert them to a list of integers
	y := readNNumbers(reader, maxLevel)

	// Remove the first element from both lists, which represents the count of levels
	x = x[1:]
	y = y[1:]

	// Convert the lists of levels into sets to eliminate duplicates
	xSet := make(map[int]bool)
	ySet := make(map[int]bool)
	for _, level := range x {
		xSet[level] = true
	}
	for _, level := range y {
		ySet[level] = true
	}

	// Check if player X has completed level 0, if so, remove it from the set
	if xSet[0] {
		delete(xSet, 0)
	}
	// If player X has not completed level 0, check if player Y has, and remove it if present
	if!xSet[0] && ySet[0] {
		delete(ySet, 0)
	}

	// Create a union of both sets to combine all unique levels completed by both players
	zSet := make(map[int]bool)
	for level := range xSet {
		zSet[level] = true
	}
	for level := range ySet {
		zSet[level] = true
	}

	// Check if the number of unique levels completed matches the maximum level
	if len(zSet)!= maxLevel {
		// If not, print a message indicating that not all levels were completed
		fmt.Println("Oh, my keyboard!")
	} else {
		// If all levels were completed, print a success message
		fmt.Println("I become the guy.")
	}
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	panic(err)
}

func readInt(bytes []byte) (int, error) {
	return strconv.Atoi(string(bytes))
}

func readNNumbers(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bytes, _ := reader.ReadBytes('\n')

	for i := 0; i < n; i++ {
		res[i], _ = readInt(bytes[x:])
		x += len(strconv.Itoa(res[i])) + 1
	}

	return res
}

