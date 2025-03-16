package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var scList []string

	// Continuously read input lines from the user until an exception occurs
	for {
		scanner.Scan()
		line := scanner.Text()
		scList = append(scList, line)
		if err := scanner.Err(); err != nil {
			break
		}
	}

	// Get the first line of input and split it into an array of strings
	numlist := strings.Split(scList[0], " ")

	// Parse the first element to get the number of sheep
	Sheep, err := strconv.Atoi(numlist[0])
	if err != nil {
		fmt.Println("Error parsing number of sheep:", err)
		return
	}

	// Parse the second element to get the number of wolves
	Wolve, err := strconv.Atoi(numlist[1])
	if err != nil {
		fmt.Println("Error parsing number of wolves:", err)
		return
	}

	// Check if the number of wolves is greater than or equal to the number of sheep
	if Wolve >= Sheep {
		fmt.Println("unsafe") // Print "unsafe" if the condition is true
	} else {
		fmt.Println("safe") // Print "safe" otherwise
	}
}

